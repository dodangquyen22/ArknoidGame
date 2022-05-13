#include "game.h"
#include "gameover.h"


Game::Game(float width, float height)
{   
    t1.loadFromFile("image/back6.png");
    t2.loadFromFile("image/ball.png");  
    t3.loadFromFile("image/paddle3.png");
    t4.loadFromFile("image/block12.png");
    taddPaddleWidth.loadFromFile("image/addWidthPad.png");
    tdoubleBall.loadFromFile("image/doubleBall.png");

    back.setTexture(t1);
    ball.setTexture(t2);
    ball2.setTexture(t2);
    ball2.setPosition(-100,0);
    ball.setPosition(284,560);
    paddle.setTexture(t3);
    paddle.setPosition(260,586);
    redBall.setTexture(t2);
    redBall.setColor(sf::Color::Red);
    addWidthPad.setTexture(taddPaddleWidth);
    doubleBall.setTexture(tdoubleBall);
   
    int k=0;
    for(int i=5;i<15;i++)
    {
        for(float j=0;j<10;j++)
        {
         brick[k].setTexture(t4);
         brick[k].setPosition(i*31,j*16);
         k++;
        }
    }
    s=rand()%100+80;
    t=rand()%80+40;
    w=rand()%40;
    redBall.setPosition(brick[s].getPosition().x,brick[s].getPosition().y);
    doubleBall.setPosition(brick[t].getPosition().x,brick[t].getPosition().y);
    addWidthPad.setPosition(brick[w].getPosition().x,brick[w].getPosition().y);
    
    scoreText.setCharacterSize(30);
    font.loadFromFile("Font/font1.otf");
    scoreText.setFont(font);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(0,0);
    scoreText.setString("Score: ");
    
    toNum.setCharacterSize(30);
    font.loadFromFile("Font/font1.otf");
    toNum.setFont(font);
    toNum.setFillColor(sf::Color::Yellow);
    toNum.setPosition(0,40);
    toNum.setString(to_string(scoreNum));

}

void Game::draw(sf::RenderWindow &window)
{
  window.draw(back);
  window.draw(ball);
  window.draw(paddle);
  window.draw(redBall);
  window.draw(doubleBall);
  window.draw(addWidthPad);
  for(int i=0;i<n;i++)
  {
      window.draw(brick[i]);
  }
  window.draw(scoreText);
  window.draw(toNum);

}

void Game::EventProcess()
{
            ball.move(dx,0);
            for(int i=0;i<n;i++)
            {
                if(isCollide(ball,brick[i])==true)
                    {
                        brick[i].setPosition(-100,0);
                        if(ball.getColor()!=sf::Color::Red) dx=-dx;
                            if(i==s)
                            {
                                isRedBallTouch=true;
                            }
                            if(i==t)
                            {
                                isDoubleBallTouch=true;
                            }
                            if(i==w)
                            {
                                isaddWidthTouch=true;
                            }
                    }
            }
            
            if(isRedBallTouch==true)
            {
                redBall.move(0,0.75);
            }
            if(isaddWidthTouch==true)
            {
                addWidthPad.move(0,0.75);
            }
            if(isDoubleBallTouch==true)
            {
                doubleBall.move(0,0.75);
            }
           

            ball.move(0,dy);
            for(int i=0;i<n;i++)
                {
                if(isCollide(ball,brick[i])==true)
                    {
                        brick[i].setPosition(-100,0);
                        if(ball.getColor()!=sf::Color::Red) dy=-dy;  
                
                          if(i==s)
                            {
                                isRedBallTouch=true;
                            }
                            if(i==t)
                            {
                                isDoubleBallTouch=true;
                            }
                            if(i=w)
                            {
                                isaddWidthTouch=true;
                            }        
                    }               
                }
            
            if(isRedBallTouch==true)
            {
                redBall.move(0,0.75);
            }
            if(isaddWidthTouch==true)
            {
                addWidthPad.move(0,0.75);
            }
            if(isDoubleBallTouch==true)
            {
                doubleBall.move(0,0.75);
            }
//Ktra paddle co cham duoc item khong            
            if(isCollide(redBall,paddle))
            {
                ball.setColor(sf::Color::Red);
                redBall.setPosition(-100,0);
            }
            if(isCollide(addWidthPad,paddle))
            {
                paddle.setScale(1.5,1);
                addWidthPad.setPosition(-100,0);
            }
            if(isCollide(doubleBall,paddle))
            {
                ball2.setPosition(ball.getPosition().x,ball.getPosition().y);
                doubleBall.setPosition(-100,0);
            }
            
            if(isCollide(ball,paddle)==true)
                    {
                        dy=-(rand()%3+2);
                    }

            sf::Vector2f g=ball.getPosition();
            if(g.x<50||g.x>550-16) dx=-dx; 
            if(g.y<0)    dy=-dy;
            if(g.y>600)
            {
                isStop=true;
            }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) paddle.move(6,0);
            if((paddle.getPosition().x+paddle.getGlobalBounds().width)>550)
            {
                paddle.setPosition(550-paddle.getGlobalBounds().width-3,586);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) paddle.move(-6,0);
            if(paddle.getPosition().x<50) paddle.setPosition(51,586);
}

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(600,600),"Game");
    window.setFramerateLimit(120);
    Game game(window.getSize().x,window.getSize().y);
    
    while(window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e))
        {
             if(e.type==sf::Event::Closed) window.close();
        }

        game.EventProcess();
        if(game.isStop==true)
        {
                GameOver over(600,600);
                window.close();
                over.run();
        }
        window.clear();
        game.draw(window);
        window.display();
    }
}

bool Game::isCollide(sf::Sprite s1, sf::Sprite s2)
{
    if(s1.getGlobalBounds().intersects(s2.getGlobalBounds()))
        {
            return true;
        }
    return false;
}


