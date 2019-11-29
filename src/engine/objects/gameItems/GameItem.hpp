#ifndef SERRARIEN_GAMEITEM_HPP
#define SERRARIEN_GAMEITEM_HPP

#include <memory>
#include <glm/glm.hpp>

#include "../../Mesh.hpp"
#include "../Object.hpp"

enum GameItemType {
    BLOCK,
    PLAYER,
    DISC
};

typedef std::pair<GameItemType, int> GameItemIdentifier;

/**
 * The class GameItem represents an object that can be rendered in the world.
 */
class GameItem : public Object {
public:
    virtual GameItemType getType() = 0;
    virtual GameItemIdentifier getIdentifier() = 0;

    MeshPtr& getMesh() override;
};

typedef std::shared_ptr<GameItem> GameItemPtr;

#endif //SERRARIEN_GAMEITEM_HPP
