#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Ships
{
private:
  sf::Texture shipTexter;
  static sf::RectangleShape shipBounds;
   sf::Sprite shipSprite;

  int x = 10;
  int y = 10;

  float speed = 80;
 int hp = 100;
  public:
  public:
  Ships();
  ~Ships();

  // static  sf::FloatRect shipBounds;
  static sf::FloatRect GetShipGloabalBounds();
  static sf::Vector2f GetShipPos();
  void Update(float deltaTime, float Width, float Height);
  void Draw(sf::RenderWindow &window);
void takeDamage(int HP);
  int getHp() const;
static int returnHp(int hp);
void reset();



};
