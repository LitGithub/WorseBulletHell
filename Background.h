#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

class background {
private:
	std::vector<sf::CircleShape*> stars;
	std::vector<sf::CircleShape*>::iterator starCounter;
public:
	void Initialize();
	void Move();
	void Draw(sf::RenderWindow* renderWindow, sf::Vector2f offset);
};