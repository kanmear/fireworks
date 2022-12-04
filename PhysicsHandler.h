#pragma once
#include "FireworkRocket.h"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class PhysicsHandler {
    public:
        static void handle(RenderWindow &window, FireworkRocket &fireworkRocket);
};