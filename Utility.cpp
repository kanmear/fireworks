#include "Utility.h"
#include <random>

using namespace sf;
using namespace std;

int Utility::windowHeight = 0;
int Utility::windowWidth = 0;

Clock Utility::clock = Clock();
Time Utility::previousTimeValue = clock.getElapsedTime();

int Utility::getRandomIntInRange(int i, int j) {
    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<> distr(i, j);

    return distr(generator);
};

int Utility::calculateFPS() {
  Time currentTimeValue = clock.getElapsedTime();
  int fps = 1 / (currentTimeValue.asSeconds() - previousTimeValue.asSeconds());
  previousTimeValue = currentTimeValue;
  return fps;
}