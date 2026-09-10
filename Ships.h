#pragma once
#include<SFML/Graphics.hpp>

class Ships
{
private:
sf::Sprite shipSprite;
sf::Texture shipTexter;

int x=10;
int y=10;

float speed=80;




public:
    Ships();
    ~Ships();

    void Update(float deltaTime,float Width,float Height);
    void Draw(sf::RenderWindow& window);
};



