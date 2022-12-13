#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

void PhysicsHandler::handle(RenderWindow &window, FireworkRocket &fireworkRocket, FireworkRocket* &pointer) {
    float gravity = 9.8f;
    float &acceleration = fireworkRocket.acceleration;
    CircleShape &shape = fireworkRocket.rocketShape;

    if (acceleration < 0.f) {
      acceleration += 0.3f * -1.f / (acceleration / 2.f);
      shape.setFillColor(Color::Red);
    } 
    
    if (shape.getPosition().y + 100.f < window.getSize().y) {
      // fireworkRocket.moveRocket(0.f, acceleration + gravity);
    } else {
      shape.setPosition(shape.getPosition().x, window.getSize().y - 100.f);
      acceleration = 0.f;
    }

    if (-acceleration - 1.0f <= gravity && -acceleration + 1.0f >= gravity) {
      shape.setFillColor(Color::Transparent);
      // delete pointer;
      // pointer = nullptr;
      // return;
      for (int i = 0; i < fireworkRocket.amountOfStars; i++) {
        CircleShape star(5.0f);
        // star.setOrigin(10, 10);
        star.setFillColor(Color::Red);
        star.setPosition(shape.getPosition().x + (i * 10), shape.getPosition().y + (i * 10));
        // star.setPosition(50, 50);
        window.draw(star);
      }
    }
}