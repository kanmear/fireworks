#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace sf;

void launchProjectile(CircleShape &shape);

void drawFireworks(RenderWindow &window, CircleShape &shape) {
  launchProjectile(shape);

  window.draw(shape);
}

void launchProjectile(CircleShape &shape) {
  shape.move(0.3f, 0.f);
}

void move(CircleShape &shape, float x, float y) {
  shape.move(x, y);
}