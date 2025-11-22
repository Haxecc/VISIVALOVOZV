#include "engine.hpp"

sf::Vector2i Entity::get_position()
{
  sf::Vector2i v(x, y);
  return v;
}

sf::Vector2i Entity::get_size()
{
  sf::Vector2i v(WIDTH, HEIGHT);
  return v;
}

void Entity::move(sf::Vector2f v)
{
  x = v.x;
  y = v.y;
  spr.move(v);
}

Hero::Hero(sf::RenderWindow& win_, sf::Texture& texture_, int hp_, int damage_, int x_, int y_, int width_, int height_, int speed_)
{ 
  sf::Sprite temp_spr(texture_);
  spr = temp_spr;
  win = win_;
  hp = hp_;
  damage = damage_;
  x = x_;
  y = y_;
  width = width_;
  speed = speed_; 
}

void Hero::keyboard_controls()
{
  unsigned [W_WIDTH, W_HEIGHT] = win.getSize();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
  {
    if (this->get_position().x < W_WIDTH-WIDTH)
    {
      this->move({speed, 0});
    }
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
  {
    if (this->get_position().x > 0)
    {
      this->move({-speed, 0});
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
  {
    if (this->get_position().y > 0)
    {
      this->move({0, -speed});
    }
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
  {
    if (this->getPosition().y < W_HEIGHT-HEIGHT)
    {
      this->move({0, speed});
    }
  }

}
