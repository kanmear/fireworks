// #include "fireworks.h"
#include "fireworks.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace sf;

// void drawFireworks(RenderWindow &window, CircleShape &shape);

int main() {
  RenderWindow window(VideoMode(200, 200), "fireworks");
  window.setFramerateLimit(120);

  CircleShape shape(100.f);
  shape.setFillColor(Color::Red);

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
    }

    // std::cout << "debug log test";
    window.clear();

    drawFireworks(window, shape);

    window.display();
  }

  return 0;
}

// void drawFireworks(RenderWindow &window, CircleShape &shape) {
//   shape.move(0.3f, 0.f);

//   window.draw(shape);
// }
