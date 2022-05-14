#include "menu.h"
#include "game.h"

Menu:: Menu(RenderWindow &windowRef):m_windowRef(windowRef) /*Khoi tao lai m_windowRef voi tham chieu windowRef, windowRef tham chieu toi cua so window,1 cua so trong */
{

    if(!font.loadFromFile("Font/font1.otf"))
    {
        cout<<"Fail to load font!";
    }   
    t1.loadFromFile("image/menuback.png");
    backg.setTexture(t1);


    text[0].setCharacterSize(80);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Red);
    text[0].setString("Play");
    text[0].setPosition(260,100);

    text[1].setCharacterSize(80);
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Red);
    text[1].setString("Score");
    text[1].setPosition(260,200);
    
    text[2].setCharacterSize(80);
    text[2].setFont(font);
    text[2].setFillColor(sf::Color::Red);
    text[2].setString("Exit");
    text[2].setPosition(260,300);
}

void Menu::draw()
{
    m_windowRef.clear();
    m_windowRef.draw(backg);
    for(int i=0;i<intMaxOption;i++)
    {
        m_windowRef.draw(text[i]);
    }
    m_windowRef.display();
}

void Menu::HandleEvent(Event &eMenu)
{
        if(eMenu.type==sf::Event::KeyReleased)
            {
                if(eMenu.key.code==sf::Keyboard::Up)
                    {
                        MoveUp();
                    }
                if(eMenu.key.code==sf::Keyboard::Down)
                    {
                        MoveDown();
                    }
                if(eMenu.key.code==sf::Keyboard::Return)
                    {
                        if(getPrsessed()==0)
                            {
                                
                            }
                        if(getPrsessed()==2)
                            {
                                m_windowRef.close();
                            }
                    }
            }
}

void Menu::MoveUp(){
    if(numChoosen-1>=-1){
        text[numChoosen].setFillColor(sf::Color::Red);
        numChoosen--;
        if(numChoosen==-1){
            numChoosen=2;
        }
        text[numChoosen].setFillColor(sf::Color::Yellow);
    }
}

void Menu::MoveDown(){
    if(numChoosen+1<=3){
        text[numChoosen].setFillColor(sf::Color::Red);
        numChoosen++;
        if(numChoosen==3){
            numChoosen=0;
        }
        text[numChoosen].setFillColor(sf::Color::Yellow);
    }
}
int Menu::getPrsessed(){
return numChoosen;
}
