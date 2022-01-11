#pragma once
#include <vector>
#include <sstream>
#include "SFML/Graphics.hpp"
#include "Player.h"
class sandbox {
private:
	std::vector<sf::CircleShape*> enemies;
	std::vector<sf::CircleShape*>::iterator enemyCounter;
	std::vector<sf::CircleShape*> bullets;
	std::vector<sf::CircleShape*>::iterator bulletCounter;
	void createBullet(int x, int y);
	void moveBullets();
	void renderHealth(sf::RenderWindow* renderWindow);
	int level = 0;
	int bulletTick = 0;
	double playerHealth = 100;
	std::stringstream SS;
	sf::Text text;
	sf::Font Font;
	sf::RectangleShape healthBar;
public:
	void Initialize(sf::Font* font);
	void Move(playerEntity* player);
	void Draw(sf::RenderWindow* renderWindow);
	void Update();
};