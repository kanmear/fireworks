#include "FireworkParticle.h"
#include <iostream>

using namespace std;

vector<FireworkParticle> FireworkParticleHandler::particlesVector = vector<FireworkParticle>();

FireworkParticle::FireworkParticle(
    Vector2<float> position,
    float vSpeed_ = 0.f,
    float hSpeed_ = 0.f,
    Color color_ = Color::Magenta,
    int fadeSpeed_ = 1,
    bool genuine_ = true,
    CircleShape particleShape_ = CircleShape())
: particleShape(particleShape_), vSpeed(vSpeed_), hSpeed(hSpeed_), fadeSpeed(fadeSpeed_), genuine(genuine_) {
    particleShape.setPosition(position.x, position.y);
    particleShape.setRadius(1.f);
    particleShape.setFillColor(color_);
}

void FireworkParticleHandler::launch(Vector2<float> position, float vSpeed_, float hSpeed_, Color color_, int fadeSpeed_, bool genuine_) {
    FireworkParticle fireworkParticle = FireworkParticle(position, vSpeed_, hSpeed_, color_, fadeSpeed_, genuine_);

    FireworkParticleHandler::particlesVector.push_back(fireworkParticle);
}