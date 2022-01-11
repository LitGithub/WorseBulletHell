#include "Player.h"

void playerEntity::Initialize() {
	entity = sf::CircleShape(10);
	entity.setPosition(500, 800);
	entity.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
}

double playerEntity::drainHealth(int damage) {
	if (health > 0)
	health -= damage;
	return health;
}

void playerEntity::Move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		drainHealth(1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if(yVel > -5) yVel -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (yVel < 5) yVel += 1;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (yVel != 0) {
			if (yVel < 0) yVel += 1;
			else
				if (yVel > 0) yVel -= 1;
		}
	if (entity.getPosition().y <= 400)
		if (yVel < 0)
			yVel = 0;
	if (entity.getPosition().y >= 980)
		if (yVel > 0)
			yVel = 0;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if (xVel > -5) xVel -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if (xVel < 5) xVel += 1;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if (xVel != 0) {
			if (xVel < 0) xVel += 1;
			else
			if (xVel > 0) xVel -= 1;
		}
	if (entity.getPosition().x <= 0)
		if(xVel < 0)
		xVel = 0;
	if (entity.getPosition().x >= 980)
		if (xVel > 0)
			xVel = 0;
	entity.setPosition(entity.getPosition().x + xVel, entity.getPosition().y + yVel);
};

void playerEntity::Draw(sf::RenderWindow* rWindow) {
		rWindow->draw(entity);
}

sf::Vector2f playerEntity::getOffset() {
	return sf::Vector2f((-1 * (500 - (entity.getPosition().x + 10))), (-1 * (800 - (entity.getPosition().y))));
	//return -1 * (500 - (entity.getPosition().x + 10));
}

double playerEntity::getHealth() {
	return health;
}

double playerEntity::getX() {
	return entity.getPosition().x + 10;
}

double playerEntity::getY() {
	return entity.getPosition().y;
}