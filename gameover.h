#pragma once
#include <SFML/Graphics.hpp>

class GameOver
{
public:
    GameOver(float width,float height);
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
    sf::Text text[2];
};

