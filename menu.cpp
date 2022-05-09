#include "menu.h"
#include "game.h"

Menu:: Menu(float width, float height)
{

if(!font.loadFromFile("Font/font1.otf")){
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
    numChoosen=0;

}

void Menu::draw(sf::RenderWindow &window){
    window.draw(backg);
    for(int i=0;i<intMaxOption;i++)
    {
        window.draw(text[i]);
    }
}

void Menu::run()
{
    sf::RenderWindow window(sf::VideoMode(600, 600),"Menu");
    Menu menu(window.getSize().x,window.getSize().y);

    while (window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type==sf::Event::Closed)
                {
                   window.close();
                }

            if(e.type==sf::Event::KeyReleased)
                {
                    if(e.key.code==sf::Keyboard::Up)
                    {
                       menu.MoveUp();
                    }
                    if(e.key.code==sf::Keyboard::Down)
                    {
                       menu.MoveDown();
                    }
                    if(e.key.code==sf::Keyboard::Return)
                    {
                        if(menu.getPrsessed()==0)
                        {
                            Game game(600,600);
                            window.close();
                            game.run();
                           
                        }
                        if(menu.getPrsessed()==2)
                        {
                            window.close();
                        }
                    }
                }
        }
            window.clear();
            menu.draw(window);
            window.display();
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
