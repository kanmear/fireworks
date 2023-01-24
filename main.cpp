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

void configureWindow(RenderWindow &window);
void mainLoop(RenderWindow &window);
void handleEvents(RenderWindow &window, Event event);
void launchRocketsAutomatically();
void updateWindow(RenderWindow &window);
void drawDebug(RenderWindow &window);
void drawRockets(RenderWindow &window);

int main() {
    // TODO replace hardcoded values with enum variables
  RenderWindow window(VideoMode(200, 200), "fireworks");
  configureWindow(window);
  DebugHandler::setFont();

  while (window.isOpen()) {
    mainLoop(window);
  }

  return 1;
};

void configureWindow(RenderWindow &window) {
  Utility::windowHeight = window.getSize().y;
  Utility::windowWidth = window.getSize().x;
  window.setFramerateLimit(120);
  window.setKeyRepeatEnabled(false);
};

void mainLoop(RenderWindow &window) {
  Event event;
  while (window.pollEvent(event)) {
    handleEvents(window, event);
  }

  launchRocketsAutomatically();
  updateWindow(window);
}

void handleEvents(RenderWindow &window, Event event) {
  if (event.type == Event::Closed)
    window.close();
  if (event.type == Event::KeyPressed) {
    if (event.key.code == Keyboard::F) {
      FireworkHandler::launch();
    }
  }
}

void launchRocketsAutomatically() {
  if (Utility::getRandomIntInRange(1, 300) == 1) {
      FireworkHandler::launch();
  }
}

void updateWindow(RenderWindow &window) {
  window.clear();

  PhysicsHandler::process();
  drawRockets(window);
  drawDebug(window);

  window.display();
}

void drawDebug(RenderWindow &window) {
  // DebugHandler::addNewText("fps", 
  //   to_string(Utility::calculateFPS()));
  // DebugHandler::addNewText("amount of particles", 
  //   to_string(FireworkParticleHandler::particlesVector.size()));

  for (int i = 0; i < DebugHandler::textVector.size(); i++) {
    window.draw(DebugHandler::textVector[i]);
  }
};

void drawRockets(RenderWindow &window) {
  VertexArray vertexes = VertexArray();

  for (int i = 0; i < FireworkHandler::fireworksVector.size(); i++) {
    Vertex vertex = FireworkHandler::fireworksVector[i].vertex;
    vertexes.append(vertex);
  }

  for (int i = 0; i < FireworkParticleHandler::particlesVector.size(); i++) {
    Vertex vertex = FireworkParticleHandler::particlesVector[i].vertex;
    vertexes.append(vertex);
  }
  
  window.draw(vertexes);
};