#pragma once
#include <SFML/Graphics/CircleShape.hpp>
// #include "FireworkParticle.h"

using namespace sf;

class FireworkRocket {
    public:
        CircleShape& shapeOfRocket;
        // FireworkParticle particles[3];

        int amountOfStars;

        float vSpeed;
        float hSpeed;
        float vAcceleration;
        float hAcceleration;
        float acceleration;

        FireworkRocket(CircleShape& shapeOfRocket_, int amt, float acc) 
        : shapeOfRocket(shapeOfRocket_), amountOfStars(amt), acceleration(acc)
        {}
    
        void moveRocket(float x, float y); 
};
