#include "PhysicsHandler.h"
#include "FireworkParticle.h"
#include "DebugHandler.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

using namespace sf;
using namespace std;

float PhysicsHandler::gravity = 9.8f;
vector<future<void>> PhysicsHandler::futures = vector<future<void>>();

void calculateParticlesMovement(int amountOfParticles, Vector2<float> position, Color color, float distanceModifier = 1.f); 
void launchParticle(Vector2<float> position, float x, float y, Color color); 

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
        // calculateParticlesMovement(rocket.amountOfStars, shape.getPosition(), 
        //   rColor, 1 / 1.1f);
        // calculateParticlesMovement(rocket.amountOfStars, shape.getPosition(), 
        //   rColor, 1 / 1.2f);
        // calculateParticlesMovement(rocket.amountOfStars, shape.getPosition(), 
        //   rColor, 1 / 1.3f);
        // calculateParticlesMovement(rocket.amountOfStars / 2, shape.getPosition(), 
        //   Utility::getRandomColor());
        // calculateParticlesMovement(rocket.amountOfStars / 2, shape.getPosition(), 
        //   Utility::getRandomColor(), 1 / 6.f);
        // calculateParticlesMovement(rocket.amountOfStars / 3, shape.getPosition(),
        //   Utility::getRandomColor());
        // calculateParticlesMovement(rocket.amountOfStars / 3, shape.getPosition(), 
        //   Utility::getRandomColor(), 1 / 8.f);

        FireworkHandler::fireworksVector.erase(
          FireworkHandler::fireworksVector.begin() + i
        );
      }
    }

    // particle trail
    if (true) {
      for (int j = 0; j < FireworkParticleHandler::particlesVector.size(); j++) {
        FireworkParticle &particle = FireworkParticleHandler::particlesVector[j];
        Vertex &vertex = particle.particleVertex;

        if (particle.genuine) {
          int rand = Utility::getRandomIntInRange(1, 1);
          if (rand == 1) {
            float mod1 = Utility::getRandomIntInRange(1, 2) == 1 ? 1.f : -1.f;
            float mod2 = Utility::getRandomIntInRange(1, 2) == 1 ? 1.f : -1.f;
            FireworkParticleHandler::launch(
              vertex.position, 
              Utility::getRandomIntInRange(1, 10) / 200.f * mod1, 
              Utility::getRandomIntInRange(1, 10) / 200.f * mod2,
              Color(
                vertex.color.r,
                vertex.color.g,
                vertex.color.b,
                122),
              2,
              false);
          }
        }
      }
    }

    for (int j = 0; j < FireworkParticleHandler::particlesVector.size(); j++) {
      // moving and deleting particles
      FireworkParticle &particle = FireworkParticleHandler::particlesVector[j];
      Vertex &vertex = particle.particleVertex;
      float &vSpeed = particle.vSpeed;
      float &hSpeed = particle.hSpeed;

      vertex.position = Vector2f(vertex.position.x + hSpeed, vertex.position.y + vSpeed);
      vSpeed /= 1.005f;
      hSpeed /= 1.005f;

      if (vertex.color.a - particle.fadeSpeed > 0) {
        vertex.color.a -= particle.fadeSpeed;
      } else {
        vertex.color.a = 0;
      }

      if (vertex.color.a <= 0) {
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

    PhysicsHandler::futures.push_back(
      async(launch::async, launchParticle, position, x * distanceModifier, y * distanceModifier, color));
  }
}

void launchParticle(Vector2f position, float x, float y, Color color) {
  int modifier = Utility::getRandomIntInRange(0, 3);
  this_thread::sleep_for(std::chrono::milliseconds(
    modifier * 50
  ));

  FireworkParticleHandler::launch(position, 
    x, 
    y, 
    color);
}