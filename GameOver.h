#pragma once
#include"State.h"

class GameOver : public State
{
private:
    /* data */
  sf::Text title;
  sf::Text hint;

public:
    GameOver(sf::RenderWindow &w , sf::Font& f);
    void handleEvent(const sf::Event& e) override ;
    void Update(float dt) override ;
    void Draw() override;

};




