#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
using namespace sf;
using namespace std;
/*
Object size:
window:800x600
ball:12x12
paddle:90x10
brick:40x20
*/
class Game
{
public:
        Game(RenderWindow &windowRef);
        Texture t1, t2, t3, t4, tball, tdoubleBall, taddPaddleWidth;
        Sprite back, ball, paddle, brick[1000], redBall, addWidthPad, doubleBall, ball2;
        void Update();
        void HandleEvent(sf::Event &event);
        void Reset();
        void draw();
        bool isCollide(Sprite s1, Sprite s2);
        bool isRedBallTouch = false;
        bool isaddWidthTouch = false;
        bool isDoubleBallTouch = false;
        int n = 1000;
        int s, t, w;
        float dx = -2, dy = -3;
        Font font;
        RenderWindow &m_windowRef;
};