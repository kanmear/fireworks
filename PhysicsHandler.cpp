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

void handleVertexes();

void calculateParticlesMovement(int amountOfParticles, Vector2<float> position, Color color, bool isRandomSpread = false, float distanceModifier = 1.f); 
void launchParticle(Vector2<float> position, float x, float y, Color color); 

// TODO replace comments with appropriately named functions
void PhysicsHandler::handle() {
  handleVertexes();
    for (int i = 0; i < FireworkHandler::fireworksVector.size(); i++) {
      // moving and deleting rockets
      FireworkRocket &rocket = FireworkHandler::fireworksVector[i];
      Vertex &vertex = rocket.vertex;
      float &vSpeed = rocket.vSpeed;
      float &hSpeed = rocket.hSpeed;

      if (vSpeed > 0.f) {
        vSpeed -= 0.6f / vSpeed;
      } 
      
      // rocket trail
      float mod1 = Utility::getRandomIntInRange(1, 2) == 1 ? 1.f : -1.f;
      float mod2 = Utility::getRandomIntInRange(1, 2) == 1 ? 1.f : -1.f;
      FireworkParticleHandler::launch(
        vertex.position,
        Utility::getRandomIntInRange(1, 10) / 50.f * mod1, 
        Utility::getRandomIntInRange(1, 10) / 50.f * mod2,
        Color::White,
        4,
        false);

      if (vertex.position.y <= Utility::windowHeight) {
        vertex.position = Vector2f(
          vertex.position.x + hSpeed, 
          vertex.position.y - vSpeed + gravity);
      } 

      // exploding rockets
      if (vertex.position.y <= rocket.explosionPositionY) {
        Color rColor1 = Utility::getRandomColor();
        Color rColor2 = Utility::getRandomColor();
        Color rColor3 = Utility::getRandomColor();
        Color rColor4 = Utility::getRandomColor();
        calculateParticlesMovement(rocket.amountOfStars / 2, vertex.position, 
          rColor1, false, 1 / 1.2f);
        calculateParticlesMovement(rocket.amountOfStars / 3, vertex.position, 
          rColor1, true, 1 / 1.3f);
        calculateParticlesMovement(rocket.amountOfStars / 3, vertex.position, 
          rColor1, true, 1 / 1.6f);
        calculateParticlesMovement(rocket.amountOfStars / 3, vertex.position, 
          rColor1, true, 1 / 1.9f);
        calculateParticlesMovement(rocket.amountOfStars / 3, vertex.position, 
          rColor2, true, 1 / 3.1f);
        calculateParticlesMovement(rocket.amountOfStars / 3, vertex.position, 
          rColor3, true, 1 / 4.6f);

        FireworkHandler::fireworksVector.erase(
          FireworkHandler::fireworksVector.begin() + i
        );
      }
    }

    // particle trail
    if (true) {
      for (int j = 0; j < FireworkParticleHandler::particlesVector.size(); j++) {
        FireworkParticle &particle = FireworkParticleHandler::particlesVector[j];
        Vertex &vertex = particle.vertex;

        if (particle.genuine) {
          int rand = Utility::getRandomIntInRange(1, 2);
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
      Vertex &vertex = particle.vertex;
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
    
    if (FireworkParticleHandler::particlesVector.size() == 0) {
      PhysicsHandler::futures.clear();
    }
}

void handleVertexes() {

}

void calculateParticlesMovement(int amountOfParticles, Vector2<float> position, Color color, bool isRandomSpread, float distanceModifier) {
  const float r = 1.f;
  float step = 360 / amountOfParticles;
  for (int j = 0; j < amountOfParticles; j++) {
    float x = r * cos(M_PI * 2 * (360 - step * j) / 360);
    float y = r * sin(M_PI * 2 * (360 - step * j) / 360);

    if (isRandomSpread) {
      float dY = Utility::getRandomIntInRange(0, 10) / 30.f;
      float dX = Utility::getRandomIntInRange(0, 10) / 30.f;
      
      x -= x < 0 ? dX * -1.f : dX * 1.f;
      y -= y < 0 ? dY * -1.f : dY * 1.f;
    }
    // cout << "x: " + to_string(x) + ", y: " + to_string(y) + "\n";

    PhysicsHandler::futures.push_back(
      async(launch::async, launchParticle, 
        position, x * distanceModifier, y * distanceModifier, color));
  }
}

void launchParticle(Vector2f position, float x, float y, Color color) {
  int modifier = Utility::getRandomIntInRange(0, 3);
  this_thread::sleep_for(std::chrono::milliseconds(
    modifier * 100
  ));

  FireworkParticleHandler::launch(position, 
    x, 
    y, 
    color);
}