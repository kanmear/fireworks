#include "DebugHandler.h"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

Font DebugHandler::font = Font();
vector<Text> DebugHandler::textVector = vector<Text>();
int DebugHandler::yPosition = 0;

void DebugHandler::setFont() {
    DebugHandler::font.loadFromFile("terminus.ttf");
};

void DebugHandler::setProperties(Text &text) {
    text.setFont(DebugHandler::font);
    text.setFillColor(Color::Red);
    text.setCharacterSize(20);
};

void DebugHandler::addNewText(String string) {
    Text text = Text();
    DebugHandler::setProperties(text);

    text.setString(string);
    text.setPosition(0, DebugHandler::yPosition);
    
    DebugHandler::textVector.push_back(text);
    DebugHandler::yPosition += 20;
}
