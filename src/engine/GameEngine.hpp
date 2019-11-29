#ifndef SERRARIEN_GAMEENGINE_HPP
#define SERRARIEN_GAMEENGINE_HPP

#include "Window.hpp"
#include "../game/Game.hpp"

class GameEngine {
private:
    Window window;
    Game game;

public:
    GameEngine();

    void loop();
};

#endif //SERRARIEN_GAMEENGINE_HPP
