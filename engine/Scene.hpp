#ifndef SERRARIEN_SCENE_HPP
#define SERRARIEN_SCENE_HPP

#include <vector>

#include "objects/gameItems/GameItem.hpp"

/**
 * The Scene is the class that stores and renders all the objects of the world.
 */
class Scene {
private:
    std::vector<GameItemPtr> gameItems;

public:
    std::vector<GameItemPtr>& getGameItems();
    void addGameItem(const GameItemPtr& gameItem);
};

#endif //SERRARIEN_SCENE_HPP
