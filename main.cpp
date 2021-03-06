#include "menu.h"
#include "game.h"
#include "gameover.h"
#include "GameStateManager.h"


int main()
{
    RenderWindow window(VideoMode(800, 600), "BreakOut", Style::Default);
    window.setFramerateLimit(120);

    Menu menu(window);
    Game game(window);
    GameOver over(window);

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                {
                 window.close();
                }
            switch (GetGameState())
            {
            case 0:
            {
                menu.HandleEvent(e);
                break;
            }
            case 1:
            {
                game.HandleEvent(e);
                break;
            }
            case 2:
            {
                over.HandleEvent(e);
                break;
            }
            }
        }

        switch (GetGameState())
        {
        case 0:
            menu.Update();
            menu.draw();
            break;
        case 1:
            if(game.isGameStarted==true)
            {
                game.pressToStart.setPosition(-1000,0);
                game.Update();
            }
            game.draw();
            break;
        case 2:
            over.Update();
            over.draw();
            break;
        default:
            break;
        }
    }
}
