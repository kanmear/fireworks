#pragma once
#include "FireworkRocket.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <future>

using namespace sf;

class PhysicsHandler {
    private:
        static float gravity;
    public:
        static void handle();
        static vector<future<void>> futures;
};