#pragma once
#include "Utility.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

using namespace sf;
using namespace std;

class FireworkRocket {
    public:
        Vertex vertex;

        int amountOfStars;

        float vSpeed;
        float hSpeed;
        float explosionPositionY;

        FireworkRocket(
            int amountOfStars_, 
            float vSpeed_,
            float hSpeed_,
            Vertex vertex_ 
        );
};

class FireworkHandler {
    public:
        static vector<FireworkRocket> fireworksVector;

        static void launch();
};