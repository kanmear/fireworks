#include "fireworks.h"
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
  
  float acceleration = -0.f;
  float gravity = 9.8f;

  CircleShape shape(50.f);
  shape.setFillColor(Color::Red);
  
  shape.setPosition(window.getSize().x / 2, window.getSize().y - 100.f);

  FireworkRocket fireworkRocket(shape, 5, acceleration);

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
          acceleration -= 14.f;
          shape.move(0.f, -1.f);
        }
      }
    }

    if (acceleration < 0.f) {
      acceleration += 0.3f * -1.f / (acceleration / 2.f);
    }
    
    // std::cout << std::to_string(shape.getPosition().y) + "\n";
    if (shape.getPosition().y + 100.f < window.getSize().y) {
      fireworkRocket.moveRocket(0.f, acceleration + gravity);
      // shape.move(0.f, acceleration + gravity);
    } else {
      shape.setPosition(shape.getPosition().x, window.getSize().y - 100.f);
      acceleration = 0.f;
    }
    
    accelerationDebug.setString("Acceleration: " + std::to_string(acceleration));
    positionDebug.setString("Position \nx:" + std::to_string(shape.getPosition().x)
      + "\ny:" + std::to_string(shape.getPosition().y));
    // std::cout << "debug log test\n";
    window.clear();

    // if (Keyboard::isKeyPressed(Keyboard::Key::F)) {
    //       std::cout << "F pressed\n";
    //       accelerate(shape);
    // }
    // drawFireworks(window, shape);
    window.draw(shape);
    window.draw(accelerationDebug);
    window.draw(positionDebug);

    window.display();
  }

  return 1;
}
