#pragma once
#include "FireworkRocket.h"
#include "FireworkParticle.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <future>

using namespace sf;

class PhysicsHandler {
    private:
        static float gravity;

        static void handleRockets();
        static void handleRocketMovement(Vertex &vertex, float &hSpeed, float &vSpeed);
        static void handleRocketExplosion(FireworkRocket &rocket, Vertex &vertex, int index);
        static void handleRocketTrail(Vertex &vertex);

        static void handleParticles();
        static void handleParticleMovement(FireworkParticle &particle, Vertex &vertex, float &hSpeed, float &vSpeed, int index);
        static void handleParticleTrail(FireworkParticle &particle, Vertex &vertex);

        static void clearFuturesVector();
    public:
        static vector<future<void>> futures;

        static void process();
};