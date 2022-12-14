#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include "DebugHandler.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

float PhysicsHandler::gravity = 9.8f;

void PhysicsHandler::handle() {
    for (int i = 0; i < FireworkHandler::fireworksVector.size(); i++) {
      FireworkRocket &rocket = FireworkHandler::fireworksVector[i];
      CircleShape &shape = rocket.rocketShape;
      float &vSpeed = rocket.vSpeed;

      int hSpeedDir = rocket.hSpeed > 0 ? 1 : -1;
      float &hSpeed = rocket.hSpeed;

      if (vSpeed == 0.f) {
        FireworkHandler::fireworksVector.erase(
          FireworkHandler::fireworksVector.begin() + i
        );
      }

      if (vSpeed > 0.f) {
        vSpeed -= 0.3f / (vSpeed / 2.f);
      } 
      // if (hSpeed > 0.f) {
      //   hSpeed -= 0.3f / (hSpeed / 2.f) * hSpeedDir;
      // } 

      // DebugHandler::addNewText("vSpeed" + to_string(i), to_string(vSpeed));
      //   + "window height " + to_string(Utility::windowHeight) + "\n";
      DebugHandler::addNewText("hSpeed" + to_string(i), to_string(hSpeed));
        + "window width " + to_string(Utility::windowWidth) + "\n";
      if (shape.getPosition().y + (shape.getRadius() * 2) <= Utility::windowHeight) {
        shape.move(hSpeed, -vSpeed + gravity);
      } else {
        shape.setPosition(
          shape.getPosition().x,
          Utility::windowHeight - (shape.getRadius() * 2) + 1.f);
        vSpeed = 0.f;
      }
    }
}