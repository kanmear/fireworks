#include "FireworkRocket.h"
#include "Settings.h"
#include <cmath>

using namespace std;

vector<FireworkRocket> FireworkHandler::fireworksVector = vector<FireworkRocket>();

FireworkRocket::FireworkRocket(
    int amountOfStars_ = Settings::DEFAULT_AMOUNT_OF_STARS, 
    float vSpeed_ = 1.f,
    float hSpeed_ = 1.f,
    Vertex vertex_ = Vertex()) 
: vertex(vertex_), amountOfStars(amountOfStars_), 
vSpeed(vSpeed_), hSpeed(hSpeed_) { 
    int modifier = Utility::getRandomIntInRange(1, 2) == 1
            ? -1
            : 1;
    hSpeed = Utility::getRandomIntInRange(1, 45) / 10.f * modifier;

    vSpeed = sqrt(Utility::windowHeight) * (2.f / 3.f) + 1.f;

    vertex.color = Color::Yellow;
    vertex.position = Vector2f(
        Utility::windowWidth / 2,
        Utility::windowHeight);
    
    explosionPositionY = Utility::windowHeight * (1.f / 3.f) 
        + Utility::getRandomIntInRange(1, Utility::windowHeight / 7);
}

void FireworkHandler::launch() {
    FireworkRocket fireworkRocket = FireworkRocket();

    FireworkHandler::fireworksVector.push_back(fireworkRocket);
}