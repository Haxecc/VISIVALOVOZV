#ifndef __ENTITIES__
#define __ENTITIES__

#include "engine.hpp"

class Entity
{
public:
  sf::Sprite spr;
  sf::Vector2f direction;

  bool collision = false;

  int hp=10;
  int damage=10;
  int x=0, y=0;
  int width=100, height=100;
  int speed=10; 
};

class Hero : public Entity
{
public:
  Hero();

  void keyboard_controls();
  void mouse_controls(sf::Vector2 cursor);
};


#endif
