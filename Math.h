#pragma once
#include<SFML/Graphics.hpp>

class Math
{

   
public:

static sf::Vector2f keepInBounds(sf::FloatRect bounds, sf::Vector2f pos,float Width,float Height );
static bool isOutScreen(sf::Vector2f bounds,float Height);
};


