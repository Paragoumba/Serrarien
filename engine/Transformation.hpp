#ifndef SERRARIEN_TRANSFORMATION_HPP
#define SERRARIEN_TRANSFORMATION_HPP

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../engine/objects/gameItems/GameItem.hpp"
#include "Camera.hpp"

class Transformation {
private:
    static glm::mat4 projectionMatrix;

public:
    static glm::mat4& getProjectionMatrix();
    static void setProjectionMatrix(float left, float right, float bottom, float top, float zNear, float zFar);
    static glm::mat4 getModelMatrix(Object* object);
    static glm::mat4 getViewMatrix(Camera& camera);
};

#endif //SERRARIEN_TRANSFORMATION_HPP
