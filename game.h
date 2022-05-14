#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
using namespace sf;
using namespace std;

class Game
{
public:
        Game(RenderWindow &windowRef);
        Texture t1,t2,t3,t4,tball,tdoubleBall,taddPaddleWidth;
        Sprite back,ball,paddle,brick[1000],redBall,addWidthPad,doubleBall,ball2;
        void Update();
        void draw();
        bool isCollide(Sprite s1,Sprite s2);
        bool isStop=false;
        bool isRedBallTouch=false;
        bool isaddWidthTouch=false;
        bool isDoubleBallTouch=false;
        int n=100;
        int s,t,w;
        float dx=-2,dy=-3;
        Font font;
        RenderWindow &m_windowRef;
};