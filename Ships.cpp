#include "Ships.h"
#include <iostream>
#include "Math.h"

sf::RectangleShape Ships::shipBounds;

Ships::Ships()
{
    //--------------Initilaze----------------------------
    shipBounds.setSize(sf::Vector2f(34, 50));
    shipBounds.setFillColor(sf::Color::Transparent);
    shipBounds.setOutlineColor(sf::Color::Blue);
    shipBounds.setOutlineThickness(0);

    //--------------Load---------------------------------
    if (shipTexter.loadFromFile("Assets/Ships/Texters/smallfreighterspr.png"))
    {
        std::cout << "ship Texters has been Load " << std::endl;
        shipSprite.setTexture(shipTexter);
        shipSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        shipSprite.setPosition(400, 300);
    }
    else
    {
        std::cout << "ship Texters has not Load" << std::endl;
    }
}

Ships::~Ships()
{
}

sf::FloatRect Ships::GetShipGloabalBounds()
{
    return shipBounds.getGlobalBounds();
}

sf::Vector2f Ships::GetShipPos()
{
    return shipBounds.getPosition() + sf::Vector2f(0, -20);
}

void Ships::Update(float deltaTime, float Width, float Height)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shipSprite.move(sf::Vector2f(x, 0) * speed * deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shipSprite.move(sf::Vector2f(-x, 0) * speed * deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        shipSprite.move(sf::Vector2f(0, -y) * speed * deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shipSprite.move(sf::Vector2f(0, y) * speed * deltaTime);
    }

    shipSprite.setPosition(Math::keepInBounds(shipSprite.getGlobalBounds(), shipSprite.getPosition(), Width, Height));
    shipBounds.setPosition(shipSprite.getPosition() + sf::Vector2f(15, 5));
}

void Ships::Draw(sf::RenderWindow &window)
{

    if (getHp() > 0)
    {
        /* code */

        window.draw(shipSprite);
        window.draw(shipBounds);
    }
}

void Ships::takeDamage(int HP)
{
    hp -= HP;
    if (hp <= 0)
    {
        std::cout << "Game Over" << std::endl;
    }
    else
    {
        std::cout << "Ship Health: " << hp << std::endl;
    }
}

int Ships::getHp() const
{
    return hp;
}

int Ships::returnHp(int hp)
{
    return 1;
}

void Ships::reset()
{
    hp = 100;
    shipSprite.setPosition(400,300);
}
