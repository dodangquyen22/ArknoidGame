#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
using namespace std;

class Game
{
public:
        Game(float width,float height);
        sf::RenderWindow window;
        sf::Texture t1,t2,t3,t4,tball,tdoubleBall,taddPaddleWidth;
        sf::Sprite back,ball,paddle,brick[1000],redBall,addWidthPad,doubleBall,ball2;
        void draw(sf::RenderWindow &window);
        void EventProcess();
        bool isCollide(sf::Sprite s1,sf::Sprite s2);
        void run();
        void isGameStop();
        bool isStop=false;
        bool isRedBallTouch=false;
        bool isaddWidthTouch=false;
        bool isDoubleBallTouch=false;
        int n=100;
        int s,t,w;
        float dx=-2,dy=-3;
        sf::Text scoreText;
        sf::Text toNum;
        int scoreNum=0;
        sf::Font font;
};