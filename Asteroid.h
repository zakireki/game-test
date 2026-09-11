#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Asteroid
{
private:
    sf::Sprite asteroidSprite;
 static sf::Texture asteroidTexter;

float speed=0;


public:
    Asteroid(float x,float y, float s );
    ~Asteroid();

    
     sf::Vector2f  GetPosition();
      void Update(float deltaTime);
    void Draw(sf::RenderWindow& window );
};



