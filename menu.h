#pragma once
#include "SFML/Graphics.hpp"
#include<SFML/Audio.hpp>
#include<SFML/Audio.hpp>
#include<time.h>
#define intMaxOption 3 
#include <iostream>
using namespace sf;
class Menu
{
public:
    Menu(RenderWindow &windowRef);
    void HandleEvent(Event &eMenu);
    void MoveUp();
    void MoveDown();
    int getPrsessed();
    void draw();
private:
    
    Texture t1;
    Sprite backg;
    Font font;
    Text text[intMaxOption];
    int numChoosen=0;
    RenderWindow &m_windowRef;//giu  cua so trong 
};

