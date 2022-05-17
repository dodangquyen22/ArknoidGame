#include "menu.h"
#include "game.h"
#include "GameStateManager.h"

Menu::Menu(RenderWindow &windowRef) : m_windowRef(windowRef) 
{

    if (!font.loadFromFile("Font/crystal.ttf"))
    {
        cout << "Fail to load font!";
    }
    t1.loadFromFile("image/mback.jpg");
    backg.setTexture(t1);

    text[0].setCharacterSize(40);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Yellow);
    text[0].setString("Play");
    text[0].setPosition(340, 150);

    text[1].setCharacterSize(40);
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Yellow);
    text[1].setString("Score");
    text[1].setPosition(340, 235);

    text[2].setCharacterSize(40);
    text[2].setFont(font);
    text[2].setFillColor(sf::Color::Yellow);
    text[2].setString("Exit");
    text[2].setPosition(340, 320);
}

void Menu::draw()
{
    m_windowRef.clear();
    m_windowRef.draw(backg);
    for (int i = 0; i < intMaxOption; i++)
    {
        m_windowRef.draw(text[i]);
    }
    m_windowRef.display();
}

void Menu::HandleEvent(Event &eMenu)
{
    if (eMenu.type == sf::Event::KeyReleased)
    {
        if (eMenu.key.code == sf::Keyboard::Up)
        {
            MoveUp();
        }
        if (eMenu.key.code == sf::Keyboard::Down)
        {
            MoveDown();
        }
        if (eMenu.key.code == sf::Keyboard::Return)
        {
            if (getPrsessed() == 0)
            {
                // 1 - Game
                ChangeStateTo(1);
            }
            if (getPrsessed() == 2)
            {
                m_windowRef.close();
            }
        }
    }
}

void Menu::Update()
{
}

void Menu::MoveUp()
{
    if (numChoosen - 1 >= -1)
    {
        text[numChoosen].setFillColor(sf::Color::Yellow);
        numChoosen--;
        if (numChoosen == -1)
        {
            numChoosen = 2;
        }
        text[numChoosen].setFillColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{
    if (numChoosen + 1 <= 3)
    {
        text[numChoosen].setFillColor(sf::Color::Yellow);
        numChoosen++;
        if (numChoosen == 3)
        {
            numChoosen = 0;
        }
        text[numChoosen].setFillColor(sf::Color::Green);
    }
}
int Menu::getPrsessed()
{
    return numChoosen;
}
