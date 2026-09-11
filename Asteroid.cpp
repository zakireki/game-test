#include "Asteroid.h"
#include "Math.h"

sf::Texture Asteroid::asteroidTexter;
Asteroid::Asteroid(float x, float y, float s)
{
    speed = s;
   y=-50;
if (asteroidTexter.getSize().x ==0)
{
    /* code */
    if (asteroidTexter.loadFromFile("Assets/Asteroids/Texters/aster.png"))
    {
        std::cout << "aster Texter has been Load " << std::endl;
    }
    else
    {
        std::cout << "aster Texter has not been Load" << std::endl;
    }
}
        asteroidSprite.setTexture(asteroidTexter);
        asteroidSprite.setTextureRect(sf::IntRect(0,0,68,68));
        asteroidSprite.setPosition(sf::Vector2f(x, y));

}

Asteroid::~Asteroid()
{
}

 sf::Vector2f Asteroid::GetPosition()
{
    return sf::Vector2f(asteroidSprite.getPosition());
}

void Asteroid::Update(float deltaTime)
{

    asteroidSprite.move(sf::Vector2f(0.0f, 10) * speed * deltaTime);
}

void Asteroid::Draw(sf::RenderWindow &window)
{

    window.draw(asteroidSprite);
}
