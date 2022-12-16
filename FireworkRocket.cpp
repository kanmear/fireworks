#include "FireworkRocket.h"

vector<FireworkRocket> FireworkHandler::fireworksVector = vector<FireworkRocket>();


FireworkRocket::FireworkRocket(
    CircleShape rocketShape_ = CircleShape(), 
    float shapeRadius = 5.0f,
    int amountOfStars_ = 5, 
    float vSpeed_ = 16.f,
    float hSpeed_ = 1.f) 
: rocketShape(rocketShape_), amountOfStars(amountOfStars_), 
vSpeed(vSpeed_), hSpeed(hSpeed_) { 
    int modifier = Utility::getRandomIntInRange(1, 2) == 1
            ? -1
            : 1;
    hSpeed = Utility::getRandomIntInRange(1, 15) / 10.f * modifier;

    rocketShape.setRadius(shapeRadius);
    rocketShape.setFillColor(Color::Red);
    rocketShape.setPosition(
        Utility::windowWidth / 2,
        Utility::windowHeight - (rocketShape.getRadius() * 2));
}

void FireworkHandler::launch() {
    FireworkRocket fireworkRocket = FireworkRocket();

    FireworkHandler::fireworksVector.push_back(fireworkRocket);
}