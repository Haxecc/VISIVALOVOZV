#include "engine.hpp"

int main(void)
{
  unsigned int HEIGHT = 600;
  unsigned int WIDTH  = 800;
  
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "VISIVALOVOZV", sf::Style::Default, sf::State::Windowed);
  window.setFramerateLimit(60);

  float speed = 10.f;

  sf::Texture texture("images/jojo.png");
  Hero hero(&window, &texture);
  hero.spr.setTextureRect(sf::IntRect({0, 0}, hero.get_position()));
  hero.spr.setPosition({WIDTH/2, HEIGHT/2});

  const auto onClose = [&window](const sf::Event::Closed&)
  {
    window.close(); 
  };

  const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
  {
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
      window.close();
    
  };

  while (window.isOpen())
  {
    window.handleEvents(onClose, onKeyPressed); 

    hero.keyboard_controls();

    window.clear();
    window.draw(hero.spr);
    window.display();
  }

  return 0;
}
