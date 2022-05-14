#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GameOver
{
public:
    GameOver(RenderWindow &windowRef);
    void draw(RenderWindow &m_windowRef);
    void HandleEvent(Event &e,RenderWindow &m_windowRef);
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

