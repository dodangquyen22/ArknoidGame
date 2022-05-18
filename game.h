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
lives:25x25
*/
class Game
{
public:
        Game(RenderWindow &windowRef);
        //Background
        Texture t1;
        Sprite back;
        //ball
        Texture t2;
        Sprite ball,secondBall;
        //paddle
        Texture t3;
        Sprite paddle;
        //brick
        Texture t4;
        Sprite brick[1000];
        int n = 1000;
        //additional item
        Texture  tdoubleBall, taddPaddleWidth;
        Sprite   redBall, addWidthPad, doubleBall;
        //game function
        void Update();
        void HandleEvent(sf::Event &event);
        void Reset();
        void draw();
        bool isCollide(Sprite s1, Sprite s2);
        void scoreUpdate();
        void playAudio(int n);
        //check-item-collect variables
        bool isRedBallTouch = false;
        bool isaddWidthTouch = false;
        bool isDoubleBallTouch = false;
        bool isGameStarted=false;
        //random value for hiding item
        int s, t, w;
        //ball moving distance
        float dx = -3, dy = -4;
        //score
        Text mScore;
        int countScore;
        //lives
        Text mLives;
        Texture tLives;
        Sprite Lives[10];
        int countLive;
        //
        Text pressToStart;
        Font font;
        Music sound,sound1,sound2;
        RenderWindow &m_windowRef;
        

};