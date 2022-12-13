#pragma once
#include "FireworkRocket.h"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class PhysicsHandler {
    private:
        static float gravity;
    public:
        static void handle();
};