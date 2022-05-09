#pragma once
#include "SFML/Graphics.hpp"
#include<SFML/Audio.hpp>
#include<SFML/Audio.hpp>
#include<time.h>
#define intMaxOption 3 
#include <iostream>
using namespace std;
class Menu
{
public:
    Menu(float width,float height);
    void draw(sf::RenderWindow &window);
    void run();
    void MoveUp();
    void MoveDown();
    int getPrsessed();
private:
    
    sf::Texture t1;
    sf::Sprite backg;
    int numChoosen;
    sf::Font font;
    sf::Text text[intMaxOption];
};

