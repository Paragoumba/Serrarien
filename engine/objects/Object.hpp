#ifndef SERRARIEN_OBJECT_HPP
#define SERRARIEN_OBJECT_HPP

#include <glm/vec2.hpp>

#include "../Mesh.hpp"

/**
 * The class Object represents an object that can be displayed in the game on the HUD or in the world.
 */
class Object {
private:
    glm::vec2 position;
    glm::vec2 scale;
    float rotation;

public:
    Object();

    virtual MeshPtr& getMesh() = 0;

    [[nodiscard]] glm::vec2 getPosition() const;
    [[nodiscard]] glm::vec2 getScale() const;
    [[nodiscard]] float getRotation() const;

    void setPosition(float x, float y);
    void setScale(float x, float y);
    void setScale(float _scale);
    void setRotation(float deg);

    void translate(float x, float y);
    void addScale(float x, float y);
    void addScale(float _scale);
    void rotate(float deg);
};

#endif //SERRARIEN_OBJECT_HPP
