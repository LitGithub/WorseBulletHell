#include <vector>
#include "SFML/Graphics.hpp"
#include "Background.h"

void background::Initialize() {
	for (int i = 0; i < rand() % 101 + 50; i++) {
		sf::CircleShape* tempStar = new sf::CircleShape(rand() % 5);
		(tempStar)->setFillColor(sf::Color((rand() % 256) / 4, (rand() % 256) / 4, (rand() % 256) / 4));
		(tempStar)->setRadius(rand() % 6 + 2);
		(tempStar)->setPosition(rand() % 1000, rand() % 1000);
		stars.push_back(tempStar);
	}
}

void background::Move() {
	if (rand() % 1000 == 500) {
		sf::CircleShape* tempStar = new sf::CircleShape(rand() % 5);
		(tempStar)->setFillColor(sf::Color((rand() % 256) / 4, (rand() % 256) / 4, (rand() % 256) / 4));
		(tempStar)->setRadius(rand() % 6 + 2);
		(tempStar)->setPosition(rand() % 1000, rand() % 200 - 200);
		stars.push_back(tempStar);
	}
	for (starCounter = stars.begin(); starCounter != stars.end(); starCounter++) {
		int y = (*starCounter)->getPosition().y;
		if (y > 1020)
			y = -20;
		else
			y++;
		(*starCounter)->setPosition((*starCounter)->getPosition().x, y);
	}
}

void background::Draw(sf::RenderWindow *rWindow, sf::Vector2f offset) {
	for (starCounter = stars.begin(); starCounter != stars.end(); starCounter++) {
		double newXPos = (*starCounter)->getRadius() / 50 * offset.x;
		double newYPos = (*starCounter)->getRadius() / 100 * offset.y;
		(*starCounter)->setPosition((*starCounter)->getPosition().x + newXPos, (*starCounter)->getPosition().y + newYPos);
		rWindow->draw(**starCounter);
		(*starCounter)->setPosition((*starCounter)->getPosition().x - newXPos, (*starCounter)->getPosition().y - newYPos);
	}
}