#include "fireworks.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace sf;

int main() {
  RenderWindow window(VideoMode(200, 200), "fireworks");
  window.setFramerateLimit(120);
  window.setKeyRepeatEnabled(false);
  
  float acceleration = -0.f;
  float gravity = 9.8f;

  CircleShape shape(50.f);
  shape.setFillColor(Color::Red);

  std::cout << std::to_string(window.getSize().y) + "\n";
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      
      // single input per press
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::F) {
          std::cout << "F pressed\n";
          acceleration -= 15.f;
          shape.move(0.f, -1.f);
        }
      }
    }
    
    if (acceleration < 0.f) {
      acceleration += 0.3f;
    }
    
    std::cout << std::to_string(shape.getPosition().y) + "\n";
    if (shape.getPosition().y + 100.f < window.getSize().y) {
      shape.move(0.f, acceleration + gravity);
    } else {
      shape.setPosition(shape.getPosition().x, window.getSize().y - 100.f);
    }
    // std::cout << "debug log test\n";
    window.clear();

    // if (Keyboard::isKeyPressed(Keyboard::Key::F)) {
    //       std::cout << "F pressed\n";
    //       accelerate(shape);
    // }
    // drawFireworks(window, shape);
    window.draw(shape);

    window.display();
  }

  return 1;
}
