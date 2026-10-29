#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Ships.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "State.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameOver.h"

StateId nextState = StateId::None;

int main()
{
    srand(time(0));
    sf::Font font;

    const int Width = 800;
    const int Height = 600;
    sf::RenderWindow window(sf::VideoMode(Width, Height), "game test", sf::Style::Default);
    window.setFramerateLimit(70);

    if (!font.loadFromFile("Assets/fonts/arial.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
        return -1;
    }

    MenuState menu(window, font);
    PlayState play(window, font);
    GameOver gameOver(window, font);

    State *current = &menu;

    Ships ship;
    AsteroidManager asteroids;

    sf::Clock clock;
    sf::Time deltaTime;
    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            current->handleEvent(event);
        }

        deltaTime = clock.restart();
        float DT = deltaTime.asSeconds();

        current->Update(DT);

        window.clear(sf::Color::Black);
        current->Draw();
        window.display();

        if (nextState != StateId::None)
        {

            if (nextState == StateId::Menu)
                current = &menu;

            else if (nextState == StateId::Play)
            {

                play.reset();
                current = &play;
            }
            else if (nextState == StateId::GameOver)
                current = &gameOver;

            nextState = StateId::None;
        }
    }

    return 0;
}