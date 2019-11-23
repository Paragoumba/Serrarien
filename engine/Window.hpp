#ifndef SERRARIEN_WINDOW_HPP
#define SERRARIEN_WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

class Window {
private:
    GLFWwindow* handle;
    const char* title;
    int width, height;
    GLFWcursor* cursor;

    double lastResizeTime;

public:
    Window(const char* title, int _width, int height);

    void setTitle(const char* newTitle);
    bool shouldClose();
    void setIcon(const char* filename);
    void setCursor(const char* path);
    void showBorder(bool visible);
    void close();
    [[nodiscard]] int getKey(int key) const;
    void swapBuffers();
    static void pollEvents();
    void getFramebufferSize(int* _width, int* _height) const;
    double getLastResizeTime();

    ~Window();
};

#endif //SERRARIEN_WINDOW_HPP
