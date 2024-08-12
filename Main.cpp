#include <iostream>
#include <fstream>
#include <map>

#include "Main.hpp"
#include "GameState.hpp"
#include "Start.hpp"
#include "Settings.hpp"
#include "Game.hpp"
#include "Data.hpp"

int main()
{
    Main m;
    int option;
    loop: while (true)
    {
        if (m.gameState==GameState::STATE_START)
        {
            option = m.start.step();
            switch (option)
            {
            case 0:
                goto exit;
            case 1:
                m.gameState = GameState::STATE_GAME;
                break;
            case 2:
                m.gameState = GameState::STATE_SETTINGS;
                break;
            default:
                goto loop;
            }
        }
        else if (m.gameState==GameState::STATE_SETTINGS)
        {
            option = m.settings.step();
            switch (option)
            {
            case 0:
                m.gameState = GameState::STATE_START;
                break;
            default:
                goto loop;
            }
        }
        else if(m.gameState==GameState::STATE_GAME)
        {
            option = m.game.step();
            switch (option)
            {
            case 0:
                m.gameState = GameState::STATE_START;
                break;
            default:
                goto loop;
            }
        }
    }
    exit: std::cout<<"Exiting game...";
}