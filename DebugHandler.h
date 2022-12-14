#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class DebugHandler {
    private: 
        static Font font;
        static int yPosition;

    public:
        static vector<Text> textVector;

        static void setFont();
        static void setProperties(Text &text);
        static void addNewText(String name, String value);
};