#include "Renderer.hpp"
#include "Transformation.hpp"
#include "../game/ResourcesManager.hpp"

Renderer::Renderer() :
    sceneShader(Shader("../res/shaders/scene_shader.vs", "../res/shaders/scene_shader.fs")),
    hudShader(Shader("../res/shaders/hud_shader.vs", "../res/shaders/hud_shader.fs")){}

void Renderer::renderScene(Scene& scene, Camera& camera, Window& window){

    sceneShader.use();
    sceneShader.setMat4f("view", Transformation::getViewMatrix(camera));

    int width, height;

    window.getFramebufferSize(&width, &height);

    sceneShader.setMat4f("projection", Transformation::getProjectionMatrix());

    for (auto& gameItem : scene.getGameItems()){

        glm::vec2 position = gameItem->getPosition();

        sceneShader.setMat4f("model", Transformation::getModelMatrix(gameItem.get()));
        sceneShader.setFloat("x", position.x);
        sceneShader.setFloat("y", position.y);

        MaterialPtr material = ResourcesManager::getMaterial(gameItem.get());
        MeshPtr mesh = ResourcesManager::getMesh(gameItem.get());

        if (material != nullptr) material->use();
        if (mesh != nullptr) mesh->render();

    }
}

void Renderer::renderHUD(HUD& hud, Window& window){

    hudShader.use();

    int width, height;

    window.getFramebufferSize(&width, &height);

    hudShader.setMat4f("projection", Transformation::getProjectionMatrix());

    for (auto& component : hud.getComponents()){

        hudShader.setMat4f("model", Transformation::getModelMatrix(component.get()));

        //MaterialPtr material = ResourcesManager::getMaterial(component.get());
        MeshPtr mesh = component->getMesh();

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, ResourcesManager::getFontTexture()->getId());

        //if (material != nullptr) material->use();
        if (mesh != nullptr) mesh->render();

    }
}
