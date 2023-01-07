#pragma once
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
using namespace std;

class Utility {
    public:
        static int windowHeight;
        static int windowWidth;

        static Clock clock;
        static Time previousTimeValue;

        static random_device randomDevice;
        static mt19937 generator;

        static int getRandomIntInRange(int i, int j);
        static int calculateFPS();
        static Color getRandomColor();
};