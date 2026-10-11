#include "AsteroidManager.h"
#include <ctime>
#include "Math.h"
#include "Ships.h"


AsteroidManager::AsteroidManager()
{

    spawnInterval = 1;
    spnInl = 0.3;
}

AsteroidManager::~AsteroidManager()
{
}

void AsteroidManager::Update(float deltaTime, float Width, float Height,Ships& ship)
{
    if (spawnClock.getElapsedTime().asSeconds() >= spawnInterval)
    {

        // random num full control
        // start + rand()%(end - start +1)
        int x = 100 + rand() % (700 - 100 + 1);
        asteroids.push_back(Asteroid(x, 0, speed));
        spawnClock.restart();
    }

    if (ship.getHp() > 0 &&spawnClock1.getElapsedTime().asSeconds() >= spnInl)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            /* code */
            bullits.push_back(Bullits(100));
            spawnClock1.restart();
        }
        
    }
    

    for (size_t i = 0; i < asteroids.size(); i++)
    {

        asteroids[i].Update(deltaTime);
    }
    for (size_t i = 0; i < bullits.size(); i++)
    {
        bullits[i].Update(deltaTime);
    }
    
    for (int i = asteroids.size() - 1; i >= 0; i--)
    {

        if (Math::isOutScreen(asteroids[i].GetPosition(), Height))
        {

            asteroids.erase(asteroids.begin() + i);
        }
    }
     for (int i = 0; i< bullits.size() ; i++)
    {

        if (Math::isUpScreen(bullits[i].GetBullitsPos(), Height))
        {

            bullits.erase(bullits.begin() + i);
            std::cout<<"bullit erase "<<std::endl;
        }
    }


    for (int i = static_cast<int>(asteroids.size()) - 1; i >= 0; i--)
    {
        if (ship.getHp() > 0 &&
            Math::checkCollision(Ships::GetShipGloabalBounds(), asteroids[i].GetAsteroidsGloabalBounds()))
        {
            ship.takeDamage(10);
            std::cout << "Collision !!!!!" << std::endl;
            asteroids.erase(asteroids.begin() + i);
        }
    }
    for (size_t i = 0; i < bullits.size(); i++)
    {
       for (size_t j = 0; j < asteroids.size(); j++)
       {
        if (Math::checkCollision(bullits[i].GetBullitsBounds(),asteroids[j].GetAsteroidsGloabalBounds()))
        {
           asteroids.erase(asteroids.begin() + j);
            bullits.erase(bullits.begin() + i);
             std::cout << "Collision bullits aster §§§ ;" << std::endl;

        }
        
       }
       
    }
    
}

void AsteroidManager::Draw(sf::RenderWindow &window)
{
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].Draw(window);
    }
    for (int i = 0; i < bullits.size(); i++)
    {
        bullits[i].Draw(window);
    }
    

}
