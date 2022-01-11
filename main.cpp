#include<iostream>
using namespace std;

#include "SFML/Graphics.hpp"

#include "HSL.hpp"
#include <random>
#include <ctime>

#include "Background.h"
#include "Player.h"
#include "Sandbox.h"

const int HEIGHT = 1000;
const int WIDTH = 1000;
const std::string title = "Galaga Reskin Basically!";


int main() {
    srand(time(NULL));

    sf::RenderWindow renderWindow(sf::VideoMode(WIDTH, HEIGHT), title);
    sf::Clock clock;
    sf::Event event;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) return 0;

    renderWindow.setFramerateLimit(60);
    background galaxy;
    playerEntity player;
    sandbox environment;
    environment.Initialize(&font);
    player.Initialize();
    galaxy.Initialize();

    while (renderWindow.isOpen()) {
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) renderWindow.close();
        }

        galaxy.Move();
        player.Move();
        environment.Move(&player);
        environment.Update();
        renderWindow.clear();

        galaxy.Draw(&renderWindow, player.getOffset());
        environment.Draw(&renderWindow);
        player.Draw(&renderWindow);

        renderWindow.display();
    }

}
