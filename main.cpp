#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include "DebugHandler.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

void drawDebug(RenderWindow &window);

int main() {
  // configure window 
  RenderWindow window(VideoMode(200, 200), "fireworks");
  window.setFramerateLimit(120);
  window.setKeyRepeatEnabled(false);
  
  // debugging
  DebugHandler::setFont();

  DebugHandler::addNewText("test");
  DebugHandler::addNewText("test2");

  // main loop
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::F) {
          // launch a rocket
        }
      }
    }

    window.clear();
    
    // draw debug info
    drawDebug(window);

    // handle rockets and particles

    window.display();
  }

  return 1;
};

void drawDebug(RenderWindow &window) {
  for (int i = 0; i < DebugHandler::textVector.size(); i++) {
    window.draw(DebugHandler::textVector[i]);
  }
};