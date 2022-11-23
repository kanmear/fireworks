#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace sf;

void drawFireworks(RenderWindow &window, CircleShape &shape) {
  shape.move(0.3f, 0.f);

  window.draw(shape);
}
