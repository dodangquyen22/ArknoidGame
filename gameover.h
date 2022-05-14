#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GameOver
{
public:
    GameOver(RenderWindow &windowRef);
    void draw();
    void HandleEvent(Event &e);
    void MoveUp();
    void MoveDown();
    int getPrsessed();
private:
    
    Texture t1;
    Sprite backg;
    int numChoosen;
    Font font;
    Text text[2];
    RenderWindow &m_windowRef;

};

