#ifndef SERRARIEN_RENDERER_HPP
#define SERRARIEN_RENDERER_HPP

#include "Shader.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "HUD.hpp"
#include "Scene.hpp"

class Renderer {
private:
    Shader sceneShader;
    Shader hudShader;

public:
    Renderer();

    void renderScene(Scene& scene, Camera& camera, Window& window);
    void renderHUD(HUD& hud, Window& window);
};

#endif //SERRARIEN_RENDERER_HPP
