#include "PhysicsHandler.h"
#include "FireworkRocket.h"
#include "FireworkParticle.h"
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
      // moving and deleting rockets
      FireworkRocket &rocket = FireworkHandler::fireworksVector[i];
      CircleShape &shape = rocket.rocketShape;
      float &vSpeed = rocket.vSpeed;
      float &hSpeed = rocket.hSpeed;

      if (vSpeed == 0.f) {
        FireworkHandler::fireworksVector.erase(
          FireworkHandler::fireworksVector.begin() + i
        );
      }

      if (vSpeed > 0.f) {
        vSpeed -= 0.3f / (vSpeed / 2.f);
      } 

      // DebugHandler::addNewText("vSpeed" + to_string(i), to_string(vSpeed));
      //   + "window height " + to_string(Utility::windowHeight) + "\n";
      // DebugHandler::addNewText("hSpeed" + to_string(i), to_string(hSpeed));
      //   + "window width " + to_string(Utility::windowWidth) + "\n";
      if (shape.getPosition().y + (shape.getRadius() * 2) <= Utility::windowHeight) {
        shape.move(hSpeed, -vSpeed + gravity);
      } else {
        shape.setPosition(
          shape.getPosition().x,
          Utility::windowHeight - (shape.getRadius() * 2) + 1.f);
        vSpeed = 0.f;
      }

      // exploding rockets
      if (rocket.alive && 
      shape.getPosition().y <= Utility::windowHeight * (1.f / 3.f)) {
        shape.setFillColor(Color::Transparent);
        rocket.alive = false;
        
        const float d1 = 1.f;
        float d = 1.f;
        float step = 1.f / rocket.amountOfStars * 4.f;
        for (int j = 0; j < rocket.amountOfStars; j++) {
          float pVspeed = d;
          float pHspeed = j % 2 != 0
            ? 1 - abs(d)
            : -(1 - abs(d));
          if (j % 2 == 0)
            d -= step;
          
          while (floor(pow(abs(pVspeed), 2.f) + pow(abs(pHspeed), 2.f)) < pow(d1, 2.f)) {
            // cout << to_string(pVspeed) + ", " + to_string(pHspeed) + "\n";
            if (pVspeed != 0)
              pVspeed += pVspeed > 0 ? 0.05f : -0.05f;            
            if (pHspeed != 0)
              pHspeed += pHspeed > 0 ? 0.05f : -0.05f;            
          }

          FireworkParticleHandler::launch(
            Vector2<float>(shape.getPosition().x, shape.getPosition().y),
            pVspeed, pHspeed);
        }
      }
    }

    for (int j = 0; j < FireworkParticleHandler::particlesVector.size(); j++) {
      // moving and deleting particles
      FireworkParticle &particle = FireworkParticleHandler::particlesVector[j];
      CircleShape &shape = particle.particleShape;
      float vSpeed = particle.vSpeed;
      float hSpeed = particle.hSpeed;

      shape.move(vSpeed, hSpeed);
      shape.setFillColor(Color(
        shape.getFillColor().r,
        shape.getFillColor().g,
        shape.getFillColor().b,
        shape.getFillColor().a == 0 ? 0 : shape.getFillColor().a - 1));

      if (shape.getFillColor().a == 0) {
        FireworkParticleHandler::particlesVector.erase(
          FireworkParticleHandler::particlesVector.begin() + j
        );
      }
    }
}