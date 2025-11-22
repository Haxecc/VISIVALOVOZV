#ifndef __ENTITIES__
#define __ENTITIES__

#include "engine.hpp"

class Entity
{
protected:
  int x;
  int y;
  int WIDTH, HEIGHT;

  sf::RenderWindow win_;

public:
  sf::Sprite spr;
  sf::Vector2f direction;

  bool collision = false;

  int hp;
  int damage;
  int speed; 

  sf::Vector2i get_position();
  sf::Vector2i get_size();
  
  void move(sf::Vector2f v);
};

class Hero : public Entity
{
public:
  Hero(sf::RenderWindow& win_, sf::Texture& texture_, int hp_=100, int damage_=10, int x_=0, int y_=0, int width_=100, int height_=100, int speed_=10);

  void keyboard_controls();
  void mouse_controls(sf::Vector2f cursor);
};


#endif
