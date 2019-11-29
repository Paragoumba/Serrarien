#ifndef SERRARIEN_CAMERA_HPP
#define SERRARIEN_CAMERA_HPP

#include <glm/vec2.hpp>

class Camera {
private:
    glm::vec2 position;
    float rotation;

public:
    Camera();

    glm::vec2 getPosition();
    float getRotation();

    void setPosition(float x, float y);
    void setRotation(float deg);

    void translate(float x, float y);
    void rotate(float deg);
};

#endif //SERRARIEN_CAMERA_HPP
