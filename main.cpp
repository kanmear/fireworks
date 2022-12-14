#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include "DebugHandler.h"
#include "Utility.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

void drawDebug(RenderWindow &window);
void drawRockets(RenderWindow &window);

int main() {
  // configure window 
  RenderWindow window(VideoMode(200, 200), "fireworks");
  Utility::windowHeight = window.getSize().y;
  Utility::windowWidth = window.getSize().x;
  window.setFramerateLimit(120);
  window.setKeyRepeatEnabled(false);
  
  // debugging
  DebugHandler::setFont();

  // main loop
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::F) {
          // launch a rocket
          FireworkHandler::launch();
        }
      }
    }

    window.clear();
    
    int randomInt = Utility::getRandomIntInRange(-10, 10);
    DebugHandler::addNewText("random int", 
      to_string(randomInt));
    DebugHandler::addNewText("amount of rockets", 
      to_string(FireworkHandler::fireworksVector.size()));

    // draw debug info
    drawDebug(window);

    // handle rockets and particles
    PhysicsHandler::handle();
    drawRockets(window);

    window.display();
  }

  return 1;
};

void drawDebug(RenderWindow &window) {
  for (int i = 0; i < DebugHandler::textVector.size(); i++) {
    window.draw(DebugHandler::textVector[i]);
  }
};

void drawRockets(RenderWindow &window) {
  for (int i = 0; i < FireworkHandler::fireworksVector.size(); i++) {
    window.draw(FireworkHandler::fireworksVector[i].rocketShape);
  }
};