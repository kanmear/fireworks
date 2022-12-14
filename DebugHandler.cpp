#include "DebugHandler.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

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

void DebugHandler::addNewText(String name, String value) {
    bool entryExists = false;
    for (int i = 0; i < textVector.size(); i++) {
        int colonIndex = textVector[i].getString().find(':');
        String entryName = textVector[i].getString().substring(0, colonIndex);
        if (entryName == name) {
            textVector[i].setString(name + ":" + value);
            entryExists = true;
        };
    };

    if (!entryExists) {
        Text text = Text();
        DebugHandler::setProperties(text);

        text.setString(name + ":" + value);
        text.setPosition(0, DebugHandler::yPosition);
        
        DebugHandler::textVector.push_back(text);
        DebugHandler::yPosition += 20;
    };
}
