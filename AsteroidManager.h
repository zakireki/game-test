#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Asteroid.h"
#include"Ships.h"

class AsteroidManager
{
private:
    std::vector<Asteroid> asteroids;
    sf::Clock spawnClock;
    float spawnInterval;
    float speed = 10;

public:
    AsteroidManager(/* args */);
    ~AsteroidManager();

    void Update(float deltaTime, float Width, float Height,Ships& ship);
    void Draw(sf::RenderWindow &window);
};
