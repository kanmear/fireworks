#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include "FireworkParticle.h"
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

    if (Utility::getRandomIntInRange(1, 300) == 1) {
        FireworkHandler::launch();
    }

    window.clear();
    
    // draw debug info
    // DebugHandler::addNewText("fps", 
    //   to_string(Utility::calculateFPS()));
    // DebugHandler::addNewText("amount of particles", 
    //   to_string(FireworkParticleHandler::particlesVector.size()));

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
  // draw rockets
  VertexArray vertexes = VertexArray();
  for (int i = 0; i < FireworkHandler::fireworksVector.size(); i++) {
    Vertex vertex = FireworkHandler::fireworksVector[i].vertex;
    vertexes.append(vertex);
  }

  // draw particles
  for (int j = 0; j < FireworkParticleHandler::particlesVector.size(); j++) {
    Vertex vertex = FireworkParticleHandler::particlesVector[j].particleVertex;
    vertexes.append(vertex);
  }
  
  window.draw(vertexes);
};