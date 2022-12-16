#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

using namespace sf;
using namespace std;

class FireworkParticle {
    public:
        CircleShape particleShape;

        float vSpeed;
        float hSpeed;
        int fadeSpeed;

        FireworkParticle(
            Vector2<float> position,
            float vSpeed_,
            float hSpeed_,
            Color color_,
            int fadeSpeed_,
            CircleShape particleShape_
        );
};

class FireworkParticleHandler {
    public:
        static vector<FireworkParticle> particlesVector;

        static void launch(Vector2<float> position, float vSpeed_, float hSpeed_, Color color_, int fadeSpeed_ = 1);
};