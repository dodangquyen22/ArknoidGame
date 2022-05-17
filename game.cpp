#include "game.h"
#include "gameover.h"
#include "GameStateManager.h"
#include <iostream>

Game::Game(RenderWindow &windowRef) : m_windowRef(windowRef)//initialise list
{
    //load image
    t1.loadFromFile("image/background.png");//backgound image
    t2.loadFromFile("image/ball.png");//ball image
    t3.loadFromFile("image/paddle.png");//paddle image
    t4.loadFromFile("image/brick.png");
    taddPaddleWidth.loadFromFile("image/addWidthPad.png");
    tdoubleBall.loadFromFile("image/doubleBall.png");
    //set texture
    back.setTexture(t1);
    ball.setTexture(t2);
    ball2.setTexture(t2);
    paddle.setTexture(t3);
    redBall.setTexture(t2);
    redBall.setColor(Color::Red);
    doubleBall.setTexture(tdoubleBall);
    addWidthPad.setTexture(taddPaddleWidth);
    //set position
    ball2.setPosition(-100, 0);
    ball.setPosition(284, 560);
    paddle.setPosition(260, 586);

    int k = 0;
    for (int i = 0; i < 14; i++)
    {
        for (float j = 0; j < 10; j++)
        {
            brick[k].setTexture(t4);
            brick[k].setPosition(20+i * 40, 20+j * 20);
            k++;
        }
    }

    Reset();
}

void Game::Reset()
{
    ball2.setPosition(-100, 0);
    ball.setPosition(284, 560);
    ball.setColor(sf::Color::White);
    paddle.setPosition(260, 586);
    srand(time(nullptr));

    int k = 0;
    for (int i = 0; i < 14; i++)
    {
        for (float j = 0; j < 10; j++)
        {
            brick[k].setTexture(t4);
            brick[k].setPosition(20+i * 40, 20+j * 20);
            k++;
        }
    }

    s = rand() % 20 + 80;
    t = rand() % 60 + 40;
    w = rand() % 40;

    redBall.setPosition(brick[s].getPosition().x, brick[s].getPosition().y);
    doubleBall.setPosition(brick[t].getPosition().x, brick[t].getPosition().y);
    addWidthPad.setPosition(brick[w].getPosition().x, brick[w].getPosition().y);
    isRedBallTouch = isDoubleBallTouch = isaddWidthTouch = false;
    paddle.setScale(1,1);
}

void Game::draw()
{
    m_windowRef.clear();
    m_windowRef.draw(back);
    m_windowRef.draw(ball);
    m_windowRef.draw(paddle);
    m_windowRef.draw(redBall);
    m_windowRef.draw(doubleBall);
    m_windowRef.draw(addWidthPad);

    for (int i = 0; i < n; i++)
    {
        m_windowRef.draw(brick[i]);
    }

    m_windowRef.display();
}

void Game::HandleEvent(sf::Event &event)
{
}

void Game::Update()
{
    ball.move(dx, 0);

    for (int i = 0; i < n; i++)
    {
        if (isCollide(ball, brick[i]) == true)
        {
            brick[i].setPosition(-100, 0);
            if (ball.getColor() != Color::Red)
                dx = -dx;
            if (i == s)
            {
                isRedBallTouch = true;
            }
            if (i == t)
            {
                isDoubleBallTouch = true;
            }
            if (i == w)
            {
                isaddWidthTouch = true;
            }
        }
    }

    if (isRedBallTouch == true)
    {
        redBall.move(0, 0.75);
    }
    if (isDoubleBallTouch == true)
    {
        doubleBall.move(0, 0.75);
    }
    if (isaddWidthTouch == true)
    {
        addWidthPad.move(0, 0.75);
    }

    ball.move(0, dy);

    for (int i = 0; i < n; i++)
    {
        if (isCollide(ball, brick[i]) == true)
        {
            brick[i].setPosition(-100, 0);
            if (ball.getColor() != Color::Red)
                dy = -dy;

            if (i == s)
            {
                isRedBallTouch = true;
            }
            if (i == t)
            {
                isDoubleBallTouch = true;
            }
            if (i == w)
            {
                isaddWidthTouch = true;
            }
        }
    }

    if (isRedBallTouch == true)
    {
        redBall.move(0, 0.75);
    }
    if (isDoubleBallTouch == true)
    {
        doubleBall.move(0, 0.75);
    }
    if (isaddWidthTouch == true)
    {
        addWidthPad.move(0, 0.75);
    }
    // Ktra paddle co cham duoc item khong
    if (isCollide(redBall, paddle))
    {
        ball.setColor(Color::Red);
        redBall.setPosition(-100, 0);
    }
    
    if (isCollide(addWidthPad, paddle))
    {
        paddle.setScale(1.5, 1);
        addWidthPad.setPosition(-100, 0);
    }
    if (isCollide(doubleBall, paddle))
    {
        ball2.setPosition(ball.getPosition().x, ball.getPosition().y);
        doubleBall.setPosition(-100, 0);
    }

    if (isCollide(ball, paddle) == true)
    {
        dy = -(rand() % 3 + 2);
    }
    //check collision with screen
    Vector2f g = ball.getPosition();
    if (g.x < 0 || g.x+16> 597)
        dx = -dx;
    if (g.y < 0)
        dy = -dy;
    if (g.y+16 > 600)
    {
        Reset();
        ChangeStateTo(2);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right))
        paddle.move(6, 0);
    if (Keyboard::isKeyPressed(Keyboard::Left))
        paddle.move(-6, 0);
    if ((paddle.getPosition().x + paddle.getGlobalBounds().width) > 597)
        paddle.setPosition(597 - paddle.getGlobalBounds().width, 586);
    if (paddle.getPosition().x < 0)
        paddle.setPosition(0, 586);
}

bool Game::isCollide(Sprite s1, Sprite s2)
{
    if (s1.getGlobalBounds().intersects(s2.getGlobalBounds()))
    {
        return true;
    }
    return false;
}
