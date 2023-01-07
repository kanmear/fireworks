#include "Utility.h"

using namespace sf;
using namespace std;

int Utility::windowHeight = 0;
int Utility::windowWidth = 0;

Clock Utility::clock = Clock();
Time Utility::previousTimeValue = clock.getElapsedTime();

random_device Utility::randomDevice;
mt19937 Utility::generator = mt19937(randomDevice());

int Utility::getRandomIntInRange(int i, int j) {
    uniform_int_distribution<> distribution(i, j);
    return distribution(generator);
};

int Utility::calculateFPS() {
  Time currentTimeValue = clock.getElapsedTime();
  int fps = 1 / (currentTimeValue.asSeconds() - previousTimeValue.asSeconds());
  previousTimeValue = currentTimeValue;
  return fps;
};

Color Utility::getRandomColor() {
  switch(getRandomIntInRange(1, 6)) {
    case 1:
      return Color::Red;
      break;
    case 2:
      return Color::Yellow;
      break;
    case 3:
      return Color::Blue;
      break;
    case 4:
      return Color::Green;
      break;
    case 5:
      return Color::Cyan;
      break;
    case 6:
      return Color::Magenta;
      break;
    default:
      return Color::White;
  }
}