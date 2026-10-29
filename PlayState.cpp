#include "PlayState.h"

PlayState::PlayState(sf::RenderWindow &w, sf::Font &f) : State(w,f)
{
    hptext.setFont(font);
    hptext.setCharacterSize(20);
    hptext.setFillColor(sf::Color::Green);
}

void PlayState::reset()
{
    ship.reset();
    astroids.reset();
}

void PlayState::handleEvent(const sf::Event &e)
{
    if (e.type == sf::Event::KeyPressed && e.key.code ==sf::Keyboard::Escape)
    {
       nextState = StateId::Menu;
    }
    
}

void PlayState::Update(float dt)
{
    float Width = window.getSize().x;
    float Height = window.getSize().y;

    ship.Update(dt ,Width , Height);
    astroids.Update(dt , Width ,Height ,ship);

    hptext.setString("HP : " + std::to_string(ship.getHp()));

    if(ship.getHp() <= 0)
    nextState = StateId::GameOver;
}

void PlayState::Draw()
{
    window.draw(hptext);
    ship.Draw(window);
    astroids.Draw(window);
}
