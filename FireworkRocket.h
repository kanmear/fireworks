#pragma once
#include <SFML/Graphics/CircleShape.hpp>

using namespace sf;

class FireworkRocket {
    private:
        CircleShape& shapeOfRocket;
        int amountOfStars;
        float acceleration;

    public:
        FireworkRocket(CircleShape& shapeOfRocket_, int amt, float acc) 
        : shapeOfRocket(shapeOfRocket_), amountOfStars(amt), acceleration(acc)
        {}
    
        void moveRocket(float x, float y); 
};
