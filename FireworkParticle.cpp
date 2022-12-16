#include "FireworkParticle.h"
#include <iostream>

using namespace std;

vector<FireworkParticle> FireworkParticleHandler::particlesVector = vector<FireworkParticle>();

FireworkParticle::FireworkParticle(
    Vector2<float> position,
    float vSpeed_ = 0.f,
    float hSpeed_ = 0.f,
    Color color_ = Color::Magenta,
    CircleShape particleShape_ = CircleShape())
: particleShape(particleShape_), vSpeed(vSpeed_), hSpeed(hSpeed_) {
    particleShape.setPosition(position.x, position.y);
    particleShape.setRadius(1.f);
    particleShape.setFillColor(color_);
}

void FireworkParticleHandler::launch(Vector2<float> position, float vSpeed_, float hSpeed_, Color color_) {
    FireworkParticle fireworkParticle = FireworkParticle(position, vSpeed_, hSpeed_, color_);

    FireworkParticleHandler::particlesVector.push_back(fireworkParticle);
}