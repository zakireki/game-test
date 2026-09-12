#include "Math.h"

sf::Vector2f Math::keepInBounds(sf::FloatRect bounds, sf::Vector2f pos, float Width, float Height)
{

    if (bounds.left + bounds.width > Width)
        return sf::Vector2f(Width - bounds.width, pos.y);

    else if (bounds.left < 0)
        return sf::Vector2f(0, pos.y);

    else if (bounds.top + bounds.height > Height)
        return sf::Vector2f(pos.x, Height - bounds.height);

    else if (bounds.top < 0)
        return sf::Vector2f(pos.x, 0);

    else
    {
        return sf::Vector2f(pos.x, pos.y);
    }
}

bool Math::isOutScreen(sf::Vector2f bounds, float Height)
{
    if (bounds.y > Height)
        return 1;
    else
        return 0;
}

bool Math::checkCollision(sf::FloatRect shipBounds, sf::FloatRect asteroids)
{
    if (shipBounds.intersects(asteroids))
    {
        return 1;
    }
    else
    {
        return false;
    }
}
