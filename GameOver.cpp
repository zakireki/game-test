#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow &w, sf::Font &f) :State(w,f)
{

    title.setFont(font);
    title.setString("GAME OVER");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(240,180));


  hint.setFont(font);
  hint.setString("R : play  again    Ecs : menu");
  hint.setCharacterSize(22);
  hint.setFillColor(sf::Color::White);
  hint.setPosition(sf::Vector2f(230,300));
}

void GameOver::handleEvent(const sf::Event &e)
{
    if(e.type != sf::Event::KeyPressed)
       return;

       if(e.key.code == sf::Keyboard::R)
         nextState = StateId::Play;
         if(e.key.code == sf::Keyboard::Escape)
         nextState = StateId::Menu;
  
    
}

void GameOver::Update(float dt)
{
}

void GameOver::Draw()
{
    window.draw(title);
    window.draw(hint);
}
