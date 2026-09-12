#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Asteroid
{
private:
  sf::Sprite asteroidSprite;
sf::RectangleShape asterBounds;
  static sf::Texture asteroidTexter;
  

  float speed = 0;

public:
  Asteroid(float x, float y, float s);
  ~Asteroid();

  sf::Vector2f GetPosition();
  sf::FloatRect GetAsteroidsGloabalBounds();

  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
};
