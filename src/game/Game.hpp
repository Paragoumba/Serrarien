#ifndef SERRARIEN_GAME_HPP
#define SERRARIEN_GAME_HPP

#include <vector>

#include "../engine/objects/gameItems/GameItem.hpp"
#include "../engine/Renderer.hpp"
#include "../engine/Window.hpp"
#include "objects/gameItems/Player.hpp"
#include "../engine/objects/components/Text.hpp"
#include "../engine/Scene.hpp"

class Game {
private:
    Renderer renderer;
    Camera camera;
    TextPtr text;
    PlayerPtr player;

    HUD hud;
    Scene scene;

    bool zoom = false;

    double lastK = 0;
    double lastF11 = 0;
    bool border = true;

    float alpha = 0;

    bool textBool = true;

    double lastTextChange = 0;

public:
    // TODO Get rid of the parameter
    void init(Window& window);
    void input(Window& window);
    // TODO Get rid of the parameter
    void update(Window& window);
    void render(Window& window);
};

#endif //SERRARIEN_GAME_HPP
