#pragma once
#include "Utility.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

using namespace sf;
using namespace std;

class FireworkRocket {
    public:
        CircleShape rocketShape;

        int amountOfStars;

        float vSpeed;
        float hSpeed;
        float explosionPositionY;

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