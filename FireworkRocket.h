#pragma once
#include "Utility.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>
// #include "FireworkParticle.h"

using namespace sf;
using namespace std;

class FireworkRocket {
    public:
        CircleShape rocketShape;
        // FireworkParticle particles[3];

        int amountOfStars;

        float vSpeed;
        float hSpeed;
        float vAcceleration;
        float hAcceleration;

        float acceleration;

        FireworkRocket(
            CircleShape rocketShape_, 
            float shapeRadius_,
            int amountOfStars_, 
            float vSpeed_,
            float hSpeed_) ;
    
};

class FireworkHandler {
    public:
        static vector<FireworkRocket> fireworksVector;

        static void launch();
};