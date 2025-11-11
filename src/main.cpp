#include <SFML/Graphics.hpp>

int main(void)
{
  unsigned int HEIGHT = 1080;
  unsigned int WIDTH  = 1920;
  
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "VIZIVALOVOZV", sf::Style::Default, sf::State::Windowed);
  window.setFramerateLimit(60);

  int HERO_H = 100;
  int HERO_W = 100;
  float speed = 10.f;

  sf::Texture texture("images/jojo.png");
  sf::Sprite hero(texture);
  hero.setTextureRect(sf::IntRect({0, 0}, {HERO_W, HERO_H}));
  hero.setPosition({860, 440});

  const auto onClose = [&window](const sf::Event::Closed&)
  {
    window.close(); 
  };

  const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
  {
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
      window.close();
    
  };

  const auto isKeyDown = [&hero, &speed, &HERO_H, &HERO_W, &HEIGHT, &WIDTH]()
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
    {
      if (hero.getPosition().x < WIDTH-HERO_W)
      {
        hero.move({speed, 0});
      }
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
    {
      if (hero.getPosition().x > 0)
      {
        hero.move({-speed, 0});
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
    {
      if (hero.getPosition().y > 0)
      {
        hero.move({0, -speed});
      }
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
    {
      if (hero.getPosition().y < HEIGHT-HERO_H)
      {
        hero.move({0, speed});
      }
    }
  };

  while (window.isOpen())
  {
    window.handleEvents(onClose, onKeyPressed); 
    isKeyDown();

    window.clear();
    window.draw(hero);
    window.display();
  }

  return 0;
}
