#pragma once
#include "Utility.h"
// #include "FireworkParticle.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

using namespace sf;
using namespace std;

class FireworkRocket {
    public:
        CircleShape rocketShape;
        bool alive = true;

        // vector<FireworkParticle> particles;
        int amountOfStars;

        float vSpeed;
        float hSpeed;

        FireworkRocket(
            CircleShape rocketShape_, 
            float shapeRadius_,
            int amountOfStars_, 
            float vSpeed_,
            float hSpeed_
        );
};

class FireworkHandler {
    public:
        static vector<FireworkRocket> fireworksVector;

        static void launch();
};