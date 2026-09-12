#include "Asteroid.h"
#include "Math.h"

sf::Texture Asteroid::asteroidTexter;
Asteroid::Asteroid(float x, float y, float s)
{  
    asterBounds.setSize(sf::Vector2f(54,44));
    asterBounds.setFillColor(sf::Color::Transparent);
    asterBounds.setOutlineColor(sf::Color::Red);
    asterBounds.setOutlineThickness(1);
 



    //---------------------------------------------------
    speed = s;
    y = -50;
    if (asteroidTexter.getSize().x == 0)
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
    asteroidSprite.setTextureRect(sf::IntRect(0, 0, 68, 68));
    asteroidSprite.setPosition(sf::Vector2f(x, y));
    asterBounds.setPosition(asteroidSprite.getPosition()+sf::Vector2f(10,10));
}

Asteroid::~Asteroid()
{
}

sf::Vector2f Asteroid::GetPosition()
{
    return sf::Vector2f(asteroidSprite.getPosition());
}

sf::FloatRect Asteroid::GetAsteroidsGloabalBounds()
{
    return asterBounds.getGlobalBounds();
}

void Asteroid::Update(float deltaTime)
{

    asteroidSprite.move(sf::Vector2f(0.0f, 10) * speed * deltaTime);
    asterBounds.setPosition(asteroidSprite.getPosition()+sf::Vector2f(10,10));
}

void Asteroid::Draw(sf::RenderWindow &window)
{

    window.draw(asteroidSprite);
    window.draw(asterBounds);
}
