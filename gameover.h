#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GameOver
{
public:
    GameOver(RenderWindow &windowRef);
    void draw();
    void HandleEvent(Event &e);
    void MoveLeft();
    void MoveRight();
    int  getPressed();
    void Update();

private:
    Texture t1;
    Sprite backg;
    int numChoosen;
    Font font;
    Text text[2];
    RenderWindow &m_windowRef;
};
