#include <string>

#include "GameState.hpp"
#include "Start.hpp"
#include "Settings.hpp"
#include "Game.hpp"

class Main
{
public:
    std::string option;
    GameState gameState;
    Start start;
    Settings settings;
    Game game;
    Main()
    {
        gameState = GameState::STATE_START;
    }
};