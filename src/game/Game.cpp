#include "Game.hpp"
#include "ResourcesManager.hpp"
#include "../engine/objects/gameItems/Block.hpp"
#include "../engine/objects/components/Text.hpp"
#include "../engine/objects/gameItems/Disc.hpp"

/**
 *
 * @param window
 */
void Game::init(Window& window){

    ResourcesManager::init();

    int winWidth, winHeight;

    window.getFramebufferSize(&winWidth, &winHeight);

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){

            // DirtBlock
            BlockPtr dirtBlock(new Block(DIRT));

            dirtBlock->translate((float) winWidth / 2 - 80 + (float) i * 16,
                                 (float) winHeight / 2 - 80 + (float) j * 16);

            scene.addGameItem(dirtBlock);

        }
    }

    // Snowman
    PlayerPtr snowman(new Player());

    snowman->translate((float) winWidth / 2 - 8, (float) winHeight / 2 - 16);

    player = snowman;
    scene.addGameItem(snowman);

    text = TextPtr(new Text("Bonjour, je suis Bernard Canetti"));

    text->setPosition((float) (winWidth - text->getText().length() * 10) / 2, 5);

    hud.addComponent(text);

}

/**
 * Handles all the inputs for the specified Window
 * @param window The Window from which to handle the inputs
 */
void Game::input(Window& window){

    if(window.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS){

        window.close();

    }

    if (window.getKey(GLFW_KEY_KP_ADD) == GLFW_PRESS){

        if (zoom){

            player->addScale(0.5f);

        } else {

            player->rotate(3.0f);

        }
    }

    if (window.getKey(GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS){

        if (zoom){

            player->addScale(-0.5f);

        } else {

            player->rotate(-3.0f);

        }
    }

    if (window.getKey(GLFW_KEY_K) == GLFW_PRESS){

        double time = glfwGetTime();

        if (time - lastK > 0.2){

            lastK = time;
            zoom = !zoom;

        }
    }

    if (window.getKey(GLFW_KEY_F11) == GLFW_PRESS){

        double time = glfwGetTime();

        if (time - lastF11 > 0.2){

            lastF11 = time;
            border = !border;
            window.showBorder(border);

        }
    }

    if (window.getKey(GLFW_KEY_W) == GLFW_PRESS){

        camera.translate(0, 1);
        player->translate(0, 1);

    }

    if (window.getKey(GLFW_KEY_A) == GLFW_PRESS){

        camera.translate(-1, 0);
        player->translate(-1, 0);

    }

    if (window.getKey(GLFW_KEY_S) == GLFW_PRESS){

        camera.translate(0, -1);
        player->translate(0, -1);

    }

    if (window.getKey(GLFW_KEY_D) == GLFW_PRESS){

        camera.translate(1, 0);
        player->translate(1, 0);

    }

    float color = (float) std::sin(glfwGetTime()) + 0.5f / 2.0f;

    if (zoom){

        glClearColor(color, -color, 0.3f, 1.0f);

    } else {

        glClearColor(0.4f, color, -color, 1.0f);

    }
}

/**
 * Updates the objects. Useful to apply physics.
 */
void Game::update(Window& window){

    alpha += 2;

    if (alpha >= 360) alpha = 0;

    int winWidth, winHeight;

    window.getFramebufferSize(&winWidth, &winHeight);

    /*float centerX = (float) winWidth / 2 - 8;
    float centerY = (float) winHeight / 2 - 16;

    player->setPosition(centerX + std::cos(glm::radians(alpha)) * 200, centerY + std::sin(glm::radians(alpha)) * 200);*/

    if (textBool){

        text->setText("Bonjour, je suis Bernard Canetti.");
        text->setPosition((float) (winWidth - text->getText().length() * 10) / 2, 5);

    } else {

        text->setText("Davilex, c'est pas si mal.");
        text->setPosition((float) (winWidth - text->getText().length() * 10) / 2, (float) winHeight - 30);

    }

    if (glfwGetTime() - lastTextChange > 5){

        lastTextChange = glfwGetTime();
        textBool = !textBool;

    }
}

void Game::render(Window& window){

    renderer.renderScene(scene, camera, window);
    renderer.renderHUD(hud, window);

}
