#include "menu.h"
#include "game.h"
#include "gameover.h"

//0-menu
//1-gameplay
//2-gameover
int gameState=1;
bool gamePlay=false;

int main()
{
    RenderWindow window(VideoMode(600,600),"Arknoid",Style::Close);
    window.setFramerateLimit(120);

    Menu menu(window);
    Game game(window);
    GameOver over(window);
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if(e.type==Event::Closed) 
                {
                    window.close();
                }
            switch (gameState)
            {
                    case 0:
                        {
                            menu.HandleEvent(e);
                            break;
                        }
                    case 2:
                        {
                            over.HandleEvent(e);
                            break;
                        }
            }
        }
            switch (gameState)
            {
            case 0:
                menu.draw();   
                break;
            case 1:
                game.Update();
                game.draw();
                break;
            case 2:
                over.draw();
                break;
            default:
                break;
            }        
    }      
}

