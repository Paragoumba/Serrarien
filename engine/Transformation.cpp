#include "Transformation.hpp"

glm::mat4 Transformation::projectionMatrix;

glm::mat4 &Transformation::getProjectionMatrix(){

    return projectionMatrix;

}

void Transformation::setProjectionMatrix(float left, float right, float bottom, float top, float zNear, float zFar){

    projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);

}

glm::mat4 Transformation::getModelMatrix(Object* object){

    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(object->getPosition(), 0));

    float rotation = object->getRotation();

    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation), glm::vec3(0, 0, 1));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(object->getScale(), 0));

    return modelMatrix;

}

glm::mat4 Transformation::getViewMatrix(Camera& camera){

    glm::vec2 position = camera.getPosition();
    float rotation = camera.getRotation();

    glm::mat4 viewMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
    viewMatrix = glm::translate(viewMatrix, glm::vec3(-position.x, -position.y, 0));

    return viewMatrix;

}