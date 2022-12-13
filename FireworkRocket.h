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
            CircleShape rocketShape_ = CircleShape(), 
            float shapeRadius = 5.0f,
            int amountOfStars_ = 5, 
            float acc = 10.0f) 
        : rocketShape(rocketShape_), amountOfStars(amountOfStars_), acceleration(acc) { 
            rocketShape.setRadius(shapeRadius);
            rocketShape.setFillColor(Color::Red);
            rocketShape.setPosition(
                Utility::windowWidth / 2,
                Utility::windowHeight - (rocketShape.getRadius() * 2));
                // Utility::windowHeight / 2);
        }
    
};

class FireworkHandler {
    public:
        static vector<FireworkRocket> fireworksVector;

        static void launch();
};