#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Ships.h"
#include "Asteroid.h"
#include "AsteroidManager.h"

int main()
{
    srand(time(0));

    const int Width = 800;
    const int Height = 600;
    sf::RenderWindow window(sf::VideoMode(Width, Height), "game test", sf::Style::Default);
    window.setFramerateLimit(70);

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
            {

                window.close();
            }
        }

        deltaTime = clock.restart();
        float DT = deltaTime.asSeconds();

        ship.Update(DT, Width, Height);
        asteroids.Update(DT, Width, Height);

        window.clear(sf::Color::Black);
        ship.Draw(window);
        asteroids.Draw(window);

        window.display();
    }

    return 0;
}