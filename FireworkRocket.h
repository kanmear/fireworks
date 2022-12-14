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
            float vSpeed_ = 16.f,
            float hSpeed_ = 1.f) 
        : rocketShape(rocketShape_), amountOfStars(amountOfStars_), vSpeed(vSpeed_), hSpeed(hSpeed_) { 
            int modifier = Utility::getRandomIntInRange(1, 2) == 1
                    ? -1
                    : 1;
            hSpeed = Utility::getRandomIntInRange(1, 2) * modifier;

            rocketShape.setRadius(shapeRadius);
            rocketShape.setFillColor(Color::Red);
            rocketShape.setPosition(
                Utility::windowWidth / 2,
                Utility::windowHeight - (rocketShape.getRadius() * 2));
        }
    
};

class FireworkHandler {
    public:
        static vector<FireworkRocket> fireworksVector;

        static void launch();
};