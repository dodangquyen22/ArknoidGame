#include "gameover.h"
#include <iostream>
#include "GameStateManager.h"

GameOver::GameOver(RenderWindow &windowRef) : m_windowRef(windowRef)
{

    if (!font.loadFromFile("Font/crystal.ttf"))
    {
        std::cout << "Fail to load font!";
    }
    t1.loadFromFile("image/gameover.jpg");
    backg.setTexture(t1);

    text[0].setCharacterSize(20);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Blue);
    text[0].setString("RePlay");
    text[0].setPosition(290, 390);

    text[1].setCharacterSize(20);
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Blue);
    text[1].setString("Exit");
    text[1].setPosition(420, 390);
    numChoosen = 0;
}

void GameOver::Update()
{
}

void GameOver::draw()
{
    m_windowRef.clear();
    m_windowRef.draw(backg);
    m_windowRef.draw(text[0]);
    m_windowRef.draw(text[1]);
    m_windowRef.display();
}

void GameOver::HandleEvent(Event &e)
{
    if (e.type == sf::Event::KeyReleased)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            MoveLeft();
        }
        if (e.key.code == sf::Keyboard::Right)
        {
            MoveRight();
        }
        if (e.key.code == sf::Keyboard::Return)
        {
            if (getPressed() == 0)
            {
                ChangeStateTo(1);
            }
            if (getPressed() == 1)
            {
                // close window
                m_windowRef.close();
            }
        }
    }
}

void GameOver::MoveLeft()
{
    if (numChoosen - 1 >= -1)
    {
        text[numChoosen].setFillColor(sf::Color::Blue);
        numChoosen--;
        if (numChoosen == -1)
        {
            numChoosen = 1;
        }
        text[numChoosen].setFillColor(sf::Color::Green);
    }
}

void GameOver::MoveRight()
{
    if (numChoosen + 1 <= 2)
    {
        text[numChoosen].setFillColor(sf::Color::Blue);
        numChoosen++;
        if (numChoosen == 2)
        {
            numChoosen = 0;
        }
        text[numChoosen].setFillColor(sf::Color::Green);
    }
}
int GameOver::getPressed()
{
    return numChoosen;
}
