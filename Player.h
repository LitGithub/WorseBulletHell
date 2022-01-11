#pragma once
#include "SFML/Graphics.hpp"

class playerEntity {
private:
	sf::CircleShape entity;
	double blasterRate = 5;
	double xVel = 0;
	double yVel = 0;
	double health = 100;
public:
	void Initialize();
	void Move();
	void Draw(sf::RenderWindow* renderWindow);
	double getHealth();
	double getX();
	double getY();
	double drainHealth(int damage);
	sf::Vector2f getOffset();
};