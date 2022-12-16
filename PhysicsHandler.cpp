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

void calculateParticlesMovement(int amountOfParticles, Vector2<float> position, Color color); 

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
        
        calculateParticlesMovement(rocket.amountOfStars, shape.getPosition(), Color::Magenta);
      }
    }

    for (int j = 0; j < FireworkParticleHandler::particlesVector.size(); j++) {
      // moving and deleting particles
      FireworkParticle &particle = FireworkParticleHandler::particlesVector[j];
      CircleShape &shape = particle.particleShape;
      float &vSpeed = particle.vSpeed;
      float &hSpeed = particle.hSpeed;

      shape.move(hSpeed, vSpeed);
      vSpeed /= 1.005f;
      hSpeed /= 1.005f;

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

void calculateParticlesMovement(int amountOfParticles, Vector2<float> position, Color color) {
  const float d1 = 1.f;
  float d = 1.f;
  float step = 1.f / amountOfParticles * 4.f;
  for (int j = 0; j < amountOfParticles; j++) {
    float pVspeed = d;
    float pHspeed = j % 2 != 0
      ? 1 - abs(d)
      : -(1 - abs(d));
    if (j % 2 == 0)
      d -= step;
    
    while (floor(pow(abs(pVspeed), 2.f) + pow(abs(pHspeed), 2.f)) < pow(d1, 2.f)) {
      // TODO test performance of this loop
      pVspeed += pVspeed > 0 ? 0.05f : -0.05f;            
      pHspeed += pHspeed > 0 ? 0.05f : -0.05f;            
    }

    FireworkParticleHandler::launch(position, pVspeed, pHspeed, color);
  }
}