#pragma once
#include <SFML/Graphics/CircleShape.hpp>

using namespace sf;

class FireworkParticle {
    public:
        CircleShape& shape;
        Color color;

        float vSpeed;
        float hSpeed;
        float vAcceleration;
        float hAcceleration;
};
