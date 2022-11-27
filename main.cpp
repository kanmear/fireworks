#include "fireworks.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace sf;

int main() {
  RenderWindow window(VideoMode(200, 200), "fireworks");
  window.setFramerateLimit(120);

  CircleShape shape(100.f);
  shape.setFillColor(Color::Red);

  while (window.isOpen()) {
    window.setKeyRepeatEnabled(false);

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      
      // if (event.type == Event::KeyPressed) {
      //   if (event.key.code == Keyboard::F) {
      //     std::cout << "F pressed\n";
      //     move(shape, 20.f, 20.f);
      //   }
      // }
    }

    // std::cout << "debug log test\n";
    window.clear();

    if (Keyboard::isKeyPressed(Keyboard::Key::F)) {
          std::cout << "F pressed\n";
          move(shape, 20.f, 20.f);
    }
    drawFireworks(window, shape);

    window.display();
  }

  return 1;
}
