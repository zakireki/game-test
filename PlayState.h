#pragma once 
#include "State.h"
#include "Ships.h"
#include "AsteroidManager.h"

class PlayState : public State
{
private:
   Ships ship ; 
   AsteroidManager astroids;
   sf::Text hptext;

public:
    PlayState(sf::RenderWindow &w , sf::Font& f);
    void reset();
    void handleEvent(const sf::Event& e) override ;
    void Update(float dt) override ;
    void Draw() override;
};

