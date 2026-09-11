#include "AsteroidManager.h"
#include <ctime>
#include "Math.h"

AsteroidManager::AsteroidManager()
{

    spawnInterval = 1;
}

AsteroidManager::~AsteroidManager()
{
}

void AsteroidManager::Update(float deltaTime, float Width, float Height)
{
    if (spawnClock.getElapsedTime().asSeconds() >= spawnInterval)
    {
        
        std::cout<<" new Asteroid !!!!!"<<std::endl;
        // random num full control
        // start + rand()%(end - start +1)
        int x = 100 + rand() % (700 - 100 + 1);
        asteroids.push_back(Asteroid(x, 0, 40));
        spawnClock.restart();
    }

        for (size_t i = 0; i < asteroids.size(); i++)
        {

            asteroids[i].Update(deltaTime);
        }
        for (int i = asteroids.size()-1; i >=0; i--)
        {

            if (Math::isOutScreen(asteroids[i].GetPosition(), Height))
            {
                std::cout<<" dletet Asteroid !!!!!"<<std::endl;
                asteroids.erase(asteroids.begin() + i);
            }
        }
}

void AsteroidManager::Draw(sf::RenderWindow &window)
{
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].Draw(window);
    }
}
