#include "Utility.h"
#include <random>

using namespace sf;
using namespace std;

int Utility::windowHeight = 0;
int Utility::windowWidth = 0;

int Utility::getRandomIntInRange(int i, int j) {
    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<> distr(i, j);

    return distr(generator);
}