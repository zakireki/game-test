#pragma once
#include<iostream>
#include<math.h>
#include<SFML/Graphics.hpp>

#include"Asteroid.h"


class AsteroidManager
{
private:
 
 std::vector<Asteroid> asteroids;
 sf::Clock spawnClock;
 float spawnInterval;
public:
    AsteroidManager(/* args */);
    ~AsteroidManager();

        void Update(float deltaTime,float Width,float Height);
    void Draw(sf::RenderWindow& window);


};



