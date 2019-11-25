#include <iostream>
#include <stb/stb_image.h>

#include "Window.hpp"
#include "exceptions/InitException.hpp"
#include "Transformation.hpp"

Window::Window(const char* _title, int _width, int _height) : title(_title), cursor(nullptr){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwSwapInterval(-1);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();

    int fullscreen = false;

    if (_width == -1 || _height == -1){

        if (_width == -1 && _height == -1){

            fullscreen = true;

        }

        glfwGetMonitorWorkarea(monitor, nullptr, nullptr,
                _width == -1 ? &_width : nullptr,
                _height == -1 ? &_height : nullptr);

    }

    width = _width;
    height = _height;

    handle = glfwCreateWindow(width, height, title, fullscreen ? monitor : nullptr, nullptr);

    if (handle == nullptr){

        glfwTerminate();

        throw InitException("Failed to create window.");

    }

    glfwMakeContextCurrent(handle);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){

        glfwTerminate();

        throw InitException("Failed to initialize GLAD.");

    }

    glViewport(0, 0, width, height);

    Transformation::setProjectionMatrix(
            0.0f,
            (float) width,
            0.0,
            (float) height,
            -1.0f,
            1.0f);

    glfwSetWindowUserPointer(handle, this);
    glfwSetFramebufferSizeCallback(handle, [](GLFWwindow* window, int newWidth, int newHeight){

        auto windowPtr = (Window*) glfwGetWindowUserPointer(window);

        windowPtr->width = newWidth;
        windowPtr->height = newHeight;

        glViewport(0, 0, newWidth, newHeight);

        windowPtr->lastResizeTime = glfwGetTime();

        Transformation::setProjectionMatrix(
                0.0f,
                (float) newWidth,
                0.0,
                (float) newHeight,
                -1.0f,
                1.0f);

    });

    glClearColor(0.4f, 0.3f, 0.5f, 1.0f);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Enable transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Enable face culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

}

void Window::setTitle(const char* _title){

    title = _title;
    glfwSetWindowTitle(handle, title);

}

bool Window::shouldClose(){

    return glfwWindowShouldClose(handle);

}

void Window::setIcon(const char* filename){

    int iconWidth, iconHeight, nrChannels;
    unsigned char* data = stbi_load(filename, &iconWidth, &iconHeight, &nrChannels, 0);

    GLFWimage icon;

    icon.width = iconWidth;
    icon.height = iconHeight;
    icon.pixels = data;

    glfwSetWindowIcon(handle, 1, &icon);

    stbi_image_free(data);

}

void Window::setCursor(const char* path){

    if (cursor != nullptr){

        glfwDestroyCursor(cursor);

    }

    int imgWidth, imgHeight, nrChannels;
    unsigned char* data = stbi_load(path, &imgWidth, &imgHeight, &nrChannels, 0);

    GLFWimage cursorImage;

    cursorImage.width = imgWidth;
    cursorImage.height = imgHeight;
    cursorImage.pixels = data;

    cursor = glfwCreateCursor(&cursorImage, 0, 0);

    stbi_image_free(data);

    glfwSetCursor(handle, cursor);

}

void Window::showBorder(bool visible){

    glfwSetWindowAttrib(handle, GLFW_DECORATED, visible ? GL_TRUE : GL_FALSE);
    int state = glfwGetWindowAttrib(handle, GLFW_DECORATED);
    std::cout << (state == GLFW_TRUE ? "true" : state == GLFW_FALSE ? "false" : "nein") << std::endl;

}

void Window::close(){

    glfwSetWindowShouldClose(handle, true);

}

int Window::getKey(int key) const {

    return glfwGetKey(handle, key);

}

void Window::swapBuffers(){

    glfwSwapBuffers(handle);

}

void Window::pollEvents(){

    glfwPollEvents();

}

void Window::getFramebufferSize(int* _width, int* _height) const {

    *_width = width;
    *_height = height;

}

double Window::getLastResizeTime(){

    return lastResizeTime;

}

Window::~Window(){

    if (cursor != nullptr){

        glfwDestroyCursor(cursor);

    }

    glfwDestroyWindow(handle);
    glfwTerminate();

}
