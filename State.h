#pragma once
#include<SFML/Graphics.hpp>

  enum class StateId {None , Menu , Play, GameOver};
    extern StateId nextState;

class State
{
protected:
    /* data */
    sf::RenderWindow& window ;
    sf::Font& font ;

public:
    State( sf::RenderWindow& w , sf::Font& f ): window(w), font(f){};
   virtual ~State(){};

   virtual void handleEvent(const sf::Event& e)=0;
   virtual void Update(float dt)= 0;
   virtual void Draw()=0;
};





