#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

void PhysicsHandler::handle(RenderWindow &window, FireworkRocket &fireworkRocket) {
    float gravity = 9.8f;
    CircleShape &shape = fireworkRocket.shapeOfRocket;

    if (fireworkRocket.acceleration < 0.f) {
      fireworkRocket.acceleration += 0.3f * -1.f / (fireworkRocket.acceleration / 2.f);
    }
    
    if (shape.getPosition().y + 100.f < window.getSize().y) {
      fireworkRocket.moveRocket(0.f, fireworkRocket.acceleration + gravity);
    } else {
      shape.setPosition(shape.getPosition().x, window.getSize().y - 100.f);
      fireworkRocket.acceleration = 0.f;
    }
}