#pragma once
#include <SFML/Graphics.hpp>

class Ships
{
private:
  sf::Texture shipTexter;
  static sf::RectangleShape shipBounds;
   sf::Sprite shipSprite;

  int x = 10;
  int y = 10;

  float speed = 80;

public:
  Ships();
  ~Ships();

  // static  sf::FloatRect shipBounds;
  static sf::FloatRect GetShipGloabalBounds();
  void Update(float deltaTime, float Width, float Height);
  void Draw(sf::RenderWindow &window);
};
