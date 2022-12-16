#include "FireworkParticle.h"

vector<FireworkParticle> FireworkParticleHandler::particlesVector = vector <FireworkParticle>();

FireworkParticle::FireworkParticle(
    Vector2<float> position,
    float vSpeed_ = 0.f,
    float hSpeed_ = 0.f,
    CircleShape particleShape_ = CircleShape())
: particleShape(particleShape_), vSpeed(vSpeed_), hSpeed(hSpeed_) {
    particleShape.setPosition(position.x, position.y);
    particleShape.setRadius(1.f);
    particleShape.setFillColor(Color::Magenta);
}

void FireworkParticleHandler::launch(Vector2<float> position, float vSpeed_, float hSpeed_) {
    FireworkParticle fireworkParticle = FireworkParticle(position, vSpeed_, hSpeed_);

    FireworkParticleHandler::particlesVector.push_back(fireworkParticle);
}