#include "Sandbox.h"
#include "HSL.hpp"

void sandbox::Initialize(sf::Font* font) {
	SS << "Level " << level;
	Font = *font;
	text.setFont(Font);
	text.setCharacterSize(30);
	text.setPosition(0, 935);
	SS.str("");
};

void sandbox::Update() {
	text.setPosition(0, 905);
	SS << "Level " << level;
	text.setString(SS.str());
	SS.str("");
}

void sandbox::Move(playerEntity *player) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		createBullet(player->getX(), player->getY());
	}
	moveBullets();
	playerHealth = player->getHealth();
};

void sandbox::createBullet(int x, int y) {
	if (bulletTick % (10 - level) == 0) {
		sf::CircleShape* tempBullet = new sf::CircleShape(rand() % 5);
		(tempBullet)->setFillColor(sf::Color(200, 200, 0));
		(tempBullet)->setRadius(3);
		(tempBullet)->setPosition(x - 3, y);
		bullets.push_back(tempBullet);
	}
}

void sandbox::moveBullets() {
	bulletTick++;
		for (bulletCounter = bullets.begin(); bulletCounter != bullets.end(); bulletCounter++) {
			int y = (*bulletCounter)->getPosition().y;
				y-=5;
			(*bulletCounter)->setPosition((*bulletCounter)->getPosition().x, y);
			HSL Rainbow = TurnToHSL((*bulletCounter)->getFillColor());
			Rainbow = HSL(((int(Rainbow.Hue) + 5) % 360), 100, 50);
			(*bulletCounter)->setFillColor(Rainbow.TurnToRGB());
		}
}


void sandbox::Draw(sf::RenderWindow* renderWindow) {
	for (bulletCounter = bullets.begin(); bulletCounter != bullets.end(); bulletCounter++)
		renderWindow->draw(**bulletCounter);
	renderWindow->draw(text);
	renderHealth(renderWindow);
};

void sandbox::renderHealth(sf::RenderWindow* renderWindow) {
	text.setPosition(0, 935);
	SS << "Health: " << playerHealth;
	text.setString(SS.str());
	SS.str("");
	renderWindow->draw(text);
	healthBar.setFillColor(sf::Color(150, 150, 150));
	healthBar.setPosition(0, 970);
	healthBar.setSize(sf::Vector2f(210, 30));
	renderWindow->draw(healthBar);
	healthBar.setFillColor(sf::Color(0, 255, 0));
	healthBar.setPosition(5, 975);
	healthBar.setSize(sf::Vector2f(playerHealth * 2, 20));
	renderWindow->draw(healthBar);
	healthBar.setFillColor(sf::Color(255, 0, 0));
	healthBar.setPosition(205, 975);
	healthBar.setSize(sf::Vector2f((playerHealth - 100) * 2, 20));
	renderWindow->draw(healthBar);
	
}