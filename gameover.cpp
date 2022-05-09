#include "gameover.h"
#include <iostream>
#include "game.h"

GameOver::GameOver(float width,float height)
{

if(!font.loadFromFile("Font/font1.otf")){
    std::cout<<"Fail to load font!";
}   
    t1.loadFromFile("image/Goverback.png");
    backg.setTexture(t1);


    text[0].setCharacterSize(80);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Blue);
    text[0].setString("RePlay");
    text[0].setPosition(220,120);

    text[1].setCharacterSize(80);
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Blue);
    text[1].setString("Exit");
    text[1].setPosition(220,320);
    numChoosen=0;
}

void GameOver::draw(sf::RenderWindow &window)
{
   window.draw(backg);
   window.draw(text[0]);
   window.draw(text[1]);
}
void GameOver::run()
{ 
    sf::RenderWindow window(sf::VideoMode(600, 600),"GameOver");
    GameOver over(window.getSize().x,window.getSize().y);

    while (window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type==sf::Event::Closed)
                {
                   window.close();
                }

            if(e.type==sf::Event::KeyReleased)
                {
                    if(e.key.code==sf::Keyboard::Up)
                    {
                       over.MoveUp();
                    }
                    if(e.key.code==sf::Keyboard::Down)
                    {
                       over.MoveDown();
                    }
                    if(e.key.code==sf::Keyboard::Return)
                    {
                       if(over.getPrsessed()==0)
                       {
                            Game game(600,600);
                            window.close();
                            game.run();
                            
                       }
                       if(over.getPrsessed()==1)
                       {
                           window.close();
                       }
                    }
                }
            }
            window.clear();
            over.draw(window);
            window.display();
    }
}

void GameOver::MoveUp(){
    if(numChoosen-1>=-1){
        text[numChoosen].setFillColor(sf::Color::Blue);
        numChoosen--;
        if(numChoosen==-1){
            numChoosen=1;
        }
        text[numChoosen].setFillColor(sf::Color::Green);
    }
}

void GameOver::MoveDown(){
    if(numChoosen+1<=2){
        text[numChoosen].setFillColor(sf::Color::Blue);
        numChoosen++;
        if(numChoosen==2){
            numChoosen=0;
        }
        text[numChoosen].setFillColor(sf::Color::Green);
    }
}
int GameOver::getPrsessed(){
return numChoosen;
}
