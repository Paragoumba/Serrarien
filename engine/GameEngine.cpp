#include <chrono>

#include "GameEngine.hpp"

#define FPS 60

GameEngine::GameEngine() : window(Window("Serrarien", 800, 600)), game(){

    window.setCursor("../res/images/cursor_dirt.png");
    window.setIcon("../res/images/blocks/dirt.png");

}

void GameEngine::loop(){

    game.init(window);

    double start = glfwGetTime();
    int i = 0;

    timespec waitingTime{0, 0};
    long waitingTimeNano = (long) (1.0 / FPS * 1'000'000'000.0);

    while (!window.shouldClose()){

        glClear(GL_COLOR_BUFFER_BIT);

        auto loopStart = std::chrono::high_resolution_clock::now();

        game.input(window);
        game.update(window);
        game.render(window);

        window.swapBuffers();
        Window::pollEvents();

        waitingTime.tv_nsec = waitingTimeNano - std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - loopStart).count();
        nanosleep(&waitingTime, nullptr);

        double time = glfwGetTime();

        ++i;

        if (time - start > 1){

            start = time;
            window.setTitle(("Serrarien - " + std::to_string(i) + " FPS").c_str());
            i = 0;

        }
    }
}
