#include "game.h"
#include "gameover.h"


Game::Game(float width, float height)
{
    t1.loadFromFile("image/back6.png");
    t2.loadFromFile("image/ball.png");  
    t3.loadFromFile("image/paddle2.png");
    t4.loadFromFile("image/block13.png");

    back.setTexture(t1);
    ball.setTexture(t2);
    ball.setPosition(284,560);
    paddle.setTexture(t3);
    paddle.setPosition(260,576);
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
    
    scoreText.setCharacterSize(30);
    font.loadFromFile("Font/font1.otf");
    scoreText.setFont(font);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(0,0);

}

void Game::draw(sf::RenderWindow &window)
{
  window.draw(back);
  window.draw(ball);
  window.draw(paddle);
  for(int i=0;i<n;i++)
  {
      window.draw(brick[i]);
  }
  window.draw(redBall);
  window.draw(scoreText);

}

void Game::EventProcess()
{
            ball.move(dx,0);
            for(int i=0;i<n;i++)
            {
                if(isCollide(ball,brick[i])==true)
                    {
                        brick[i].setPosition(-100,0);dx=-dx;
                    }
            }
            
            ball.move(0,dy);
            for(int i=0;i<n;i++)
                {
                if(isCollide(ball,brick[i])==true)
                    {
                        brick[i].setPosition(-100,0);dy=-dy;
                    }
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


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) paddle.move(10,0);
            if(paddle.getPosition().x>550-80) paddle.setPosition(550-80-4,576);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) paddle.move(-10,0);
            if(paddle.getPosition().x<50) paddle.setPosition(50,576);
}

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(600,600),"Game");
    window.setFramerateLimit(60);
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

void Game::update()
{
    
}

