#include "PhysicsHandler.h"
#include "FireworkParticle.h"
#include "DebugHandler.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

float PhysicsHandler::gravity = 9.8f;

void calculateParticlesMovement(int amountOfParticles, Vector2<float> position, Color color, float distanceModifier = 1.f); 

void PhysicsHandler::handle() {
    for (int i = 0; i < FireworkHandler::fireworksVector.size(); i++) {
      // moving and deleting rockets
      FireworkRocket &rocket = FireworkHandler::fireworksVector[i];
      CircleShape &shape = rocket.rocketShape;
      float &vSpeed = rocket.vSpeed;
      float &hSpeed = rocket.hSpeed;

      if (vSpeed > 0.f) {
        vSpeed -= 0.6f / vSpeed;
      } 
      
      // rocket trail
      float mod1 = Utility::getRandomIntInRange(1, 2) == 1 ? 1.f : -1.f;
      float mod2 = Utility::getRandomIntInRange(1, 2) == 1 ? 1.f : -1.f;
      FireworkParticleHandler::launch(
        shape.getPosition(), 
        Utility::getRandomIntInRange(1, 10) / 50.f * mod1, 
        Utility::getRandomIntInRange(1, 10) / 50.f * mod2,
        Color::White,
        4,
        false);

      if (shape.getPosition().y + (shape.getRadius() * 2) <= Utility::windowHeight) {
        shape.move(hSpeed, -vSpeed + gravity);
      } 

      // exploding rockets
      if (shape.getPosition().y <= rocket.explosionPositionY) {
        Color rColor = Utility::getRandomColor();
        calculateParticlesMovement(rocket.amountOfStars, shape.getPosition(), 
          rColor);
        calculateParticlesMovement(rocket.amountOfStars, shape.getPosition(), 
          rColor, 1 / 1.1f);
        calculateParticlesMovement(rocket.amountOfStars, shape.getPosition(), 
          rColor, 1 / 1.2f);
        calculateParticlesMovement(rocket.amountOfStars, shape.getPosition(), 
          rColor, 1 / 1.3f);
        calculateParticlesMovement(rocket.amountOfStars / 2, shape.getPosition(), 
          Utility::getRandomColor());
        calculateParticlesMovement(rocket.amountOfStars / 2, shape.getPosition(), 
          Utility::getRandomColor(), 1 / 6.f);
        calculateParticlesMovement(rocket.amountOfStars / 3, shape.getPosition(),
          Utility::getRandomColor());
        calculateParticlesMovement(rocket.amountOfStars / 3, shape.getPosition(), 
          Utility::getRandomColor(), 1 / 8.f);

        FireworkHandler::fireworksVector.erase(
          FireworkHandler::fireworksVector.begin() + i
        );
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

      if (shape.getFillColor().a - particle.fadeSpeed > 0) {
        shape.setFillColor(Color(
          shape.getFillColor().r,
          shape.getFillColor().g,
          shape.getFillColor().b,
          shape.getFillColor().a - particle.fadeSpeed));
      } else {
        shape.setFillColor(Color(
          shape.getFillColor().r,
          shape.getFillColor().g,
          shape.getFillColor().b,
          0));
      }

      if (shape.getFillColor().a <= 0) {
        FireworkParticleHandler::particlesVector.erase(
          FireworkParticleHandler::particlesVector.begin() + j
        );
      }
    }
}

void calculateParticlesMovement(int amountOfParticles, Vector2<float> position, Color color, float distanceModifier) {
  const float r = 1.f;
  float step = 360 / amountOfParticles;
  for (int j = 0; j < amountOfParticles; j++) {
    float x = r * cos(M_PI * 2 * (360 - step * j) / 360);
    float y = r * sin(M_PI * 2 * (360 - step * j) / 360);

    FireworkParticleHandler::launch(position, 
      x * distanceModifier, 
      y * distanceModifier, 
      color);
  }
}