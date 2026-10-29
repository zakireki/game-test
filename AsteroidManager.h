#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Asteroid.h"
#include"Ships.h"
#include"Bullits.h"

class AsteroidManager
{
private:
//bullits
std::vector<Bullits> bullits;
float spnInl;
  sf::Clock spawnClock1;
//asteroids
std::vector<Asteroid> asteroids;
    sf::Clock spawnClock;
    float spawnInterval=0;
    float speed = 25;

    

public:
    AsteroidManager(/* args */);
    ~AsteroidManager();

    void Update(float deltaTime, float Width, float Height,Ships& ship);
    void Draw(sf::RenderWindow &window);
    void reset();
};
