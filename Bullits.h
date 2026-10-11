#pragma once
#include<SFML/Graphics.hpp>

class Bullits
{
private:
    sf::RectangleShape bullitRect;

    float speed = 10;
public:
    Bullits( float s);
    ~Bullits();

    sf::Vector2f GetBullitsPos();
    sf::FloatRect GetBullitsBounds();

  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
};

