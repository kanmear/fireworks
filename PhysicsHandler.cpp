#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include "DebugHandler.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace sf;

float PhysicsHandler::gravity = 9.8f;

void PhysicsHandler::handle() {
    for (int i = 0; i < FireworkHandler::fireworksVector.size(); i++) {
      FireworkRocket &rocket = FireworkHandler::fireworksVector[i];
      CircleShape &shape = rocket.rocketShape;
      float &acceleration = rocket.acceleration;
      // std::cout << to_string(acceleration) + "\n";

      if (acceleration > 0.f) {
        std::cout << "lowering acceleration " + to_string(acceleration) + "\n";
        acceleration -= 0.3f / (acceleration / 2.f);
      } 

      // std::cout << "y position + diameter " + to_string(shape.getPosition().y + (shape.getRadius() * 2)) 
      DebugHandler::addNewText("Speed" + to_string(i), to_string(acceleration));
        + "window height " + to_string(Utility::windowHeight) + "\n";
      if (shape.getPosition().y + (shape.getRadius() * 2) <= Utility::windowHeight) {
        // std::cout << "moving shape " + to_string(acceleration) + "\n";
        shape.move(0.f, -acceleration + gravity);
      } else {
        // std::cout << "hit floor " + to_string(acceleration) + "\n";
        shape.setPosition(
          shape.getPosition().x,
          Utility::windowHeight - (shape.getRadius() * 2) + 1.f);
        acceleration = 0.f;
      }
    }

    // if (-acceleration - 1.0f <= gravity && -acceleration + 1.0f >= gravity) {
    //   shape.setFillColor(Color::Transparent);
    //   // delete pointer;
    //   // pointer = nullptr;
    //   // return;
    //   for (int i = 0; i < fireworkRocket.amountOfStars; i++) {
    //     CircleShape star(5.0f);
    //     // star.setOrigin(10, 10);
    //     star.setFillColor(Color::Red);
    //     star.setPosition(shape.getPosition().x + (i * 10), shape.getPosition().y + (i * 10));
    //     // star.setPosition(50, 50);
    //     window.draw(star);
    //   }
    // }
}