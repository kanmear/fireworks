#include "FireworkRocket.h"
#include <cmath>

using namespace std;

vector<FireworkRocket> FireworkHandler::fireworksVector = vector<FireworkRocket>();

FireworkRocket::FireworkRocket(
    CircleShape rocketShape_ = CircleShape(), 
    float shapeRadius = 2.0f,
    int amountOfStars_ = 48, 
    float vSpeed_ = 1.f,
    float hSpeed_ = 1.f) 
: rocketShape(rocketShape_), amountOfStars(amountOfStars_), 
vSpeed(vSpeed_), hSpeed(hSpeed_) { 
    int modifier = Utility::getRandomIntInRange(1, 2) == 1
            ? -1
            : 1;
    hSpeed = Utility::getRandomIntInRange(1, 15) / 10.f * modifier;

    vSpeed = sqrt(Utility::windowHeight) * (2.f / 3.f) + 1.f;

    rocketShape.setRadius(shapeRadius);
    rocketShape.setFillColor(Color::Yellow);
    rocketShape.setPosition(
        Utility::windowWidth / 2,
        Utility::windowHeight - (rocketShape.getRadius() * 2));
}

void FireworkHandler::launch() {
    FireworkRocket fireworkRocket = FireworkRocket();

    FireworkHandler::fireworksVector.push_back(fireworkRocket);
}