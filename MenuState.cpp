#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow &w, sf::Font &f) : State(w,f)
{
    title.setFont(font);
    title.setString("ASTROIDS");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(260,180));


  hint.setFont(font);
  hint.setString("Prees Enter to play");
  hint.setCharacterSize(48);
  hint.setFillColor(sf::Color::White);
  hint.setPosition(sf::Vector2f(290,300));
}

void MenuState::handleEvent(const sf::Event &e)
{
    if (e.type == sf::Event::KeyPressed && e.key.code ==sf::Keyboard::Enter)
    {
       nextState = StateId::Play;
    }
    
}

void MenuState::Update(float dt)
{
}

void MenuState::Draw()
{
    window.draw(title);
    window.draw(hint);
}
