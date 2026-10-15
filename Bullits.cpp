#include "Bullits.h"
#include"Ships.h"

Bullits::Bullits( float s)
{
    bullitRect.setFillColor(sf::Color::White);
    bullitRect.setSize(sf::Vector2f(4,8));
    bullitRect.setPosition(Ships::GetShipPos());
    

    speed = s;

}

Bullits::~Bullits()
{
}

sf::Vector2f Bullits::GetBullitsPos()
{
    return  sf::Vector2f(sf::Vector2f(bullitRect.getPosition()));
}

sf::FloatRect Bullits::GetBullitsBounds()
{
    return sf::FloatRect(sf::FloatRect(bullitRect.getGlobalBounds()));
}

void Bullits::Update(float deltaTime)
{
    bullitRect.setPosition(bullitRect.getPosition()+ sf::Vector2f(0,-10)*speed*deltaTime);
}

void Bullits::Draw(sf::RenderWindow &window)
{
    window.draw(bullitRect);
}
