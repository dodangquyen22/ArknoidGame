#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
using namespace std;

class Game
{
public:
        Game(float width,float height);
        sf::RenderWindow window;
        sf::Texture t1,t2,t3,t4,tball,taddPaddleWidth;
        sf::Sprite back,ball,paddle,brick[1000],redBall,addPaddleWidth;
        void draw(sf::RenderWindow &window);
        void EventProcess();
        bool isCollide(sf::Sprite s1,sf::Sprite s2);
        void run();
        void update();
        void isGameStop();
        bool isStop=false;
        int n=100;
        int s=rand()%100;
        float dx=-4,dy=-5;
        sf::Text scoreText;
        int scoreNum=0;
        sf::Font font;
};