#pragma once
#include"State.h"

class MenuState : public State
{
private:
    /* data */
  sf::Text title;
  sf::Text hint;

public:
    MenuState(sf::RenderWindow &w , sf::Font& f);
    void handleEvent(const sf::Event& e) override ;
    void Update(float dt) override ;
    void Draw() override;

};




