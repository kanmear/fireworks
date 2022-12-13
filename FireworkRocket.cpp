#include "FireworkRocket.h"

vector<FireworkRocket> FireworkHandler::fireworksVector = vector<FireworkRocket>();

void FireworkHandler::launch() {
    FireworkRocket fireworkRocket = FireworkRocket();

    FireworkHandler::fireworksVector.push_back(fireworkRocket);
}