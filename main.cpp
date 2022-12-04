#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace sf;

int main() {
  RenderWindow window(VideoMode(200, 200), "fireworks");
  window.setFramerateLimit(120);
  window.setKeyRepeatEnabled(false);
  
  // accelerationDebug and font
  Font font;
  font.loadFromFile("terminus.ttf");
  
  Text accelerationDebug;
  accelerationDebug.setFont(font);
  accelerationDebug.setCharacterSize(24);
  accelerationDebug.setFillColor(Color::Red);

  Text positionDebug;
  positionDebug.setPosition(positionDebug.getPosition().x, positionDebug.getPosition().y + 30.f);
  positionDebug.setFont(font);
  positionDebug.setCharacterSize(24);
  positionDebug.setFillColor(Color::Red);
  

  CircleShape shape(50.f);
  shape.setFillColor(Color::Red);
  
  shape.setPosition(window.getSize().x / 2, window.getSize().y - 100.f);

  FireworkRocket fireworkRocket(shape, 5, 0.f);
  float &acceleration = fireworkRocket.acceleration;

  std::cout << std::to_string(window.getSize().y) + "\n";
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      
      // single input per press
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::F) {
          // std::cout << "F pressed\n";
          fireworkRocket.acceleration -= 14.3f;
          fireworkRocket.shapeOfRocket.move(0.f, -1.f);
        }
        else if (event.key.code == Keyboard::T) {
          fireworkRocket.acceleration = 0.f;
          fireworkRocket.shapeOfRocket.move(0.f, -1.f);
        }
      }
    }

    PhysicsHandler::handle(window, fireworkRocket);

    window.clear();

    accelerationDebug.setString("Acceleration: " + std::to_string(acceleration));
    positionDebug.setString("Position \nx:" + std::to_string(fireworkRocket.shapeOfRocket.getPosition().x)
      + "\ny:" + std::to_string(shape.getPosition().y));

    window.draw(shape);
    window.draw(accelerationDebug);
    window.draw(positionDebug);

    window.display();
  }

  return 1;
}
