#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Utility {
    public:
        static int windowHeight;
        static int windowWidth;

        static Clock clock;
        static Time previousTimeValue;

        static int getRandomIntInRange(int i, int j);
        static int calculateFPS();
};