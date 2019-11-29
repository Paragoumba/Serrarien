#ifndef SERRARIEN_HUD_HPP
#define SERRARIEN_HUD_HPP

#include <vector>

#include "objects/gameItems/GameItem.hpp"
#include "objects/components/Component.hpp"

/**
 * The HUD is a class that contains and renders all the objects of the interface.
 */
class HUD {
private:
    std::vector<ComponentPtr> components;

public:
    std::vector<ComponentPtr>& getComponents();
    void addComponent(const ComponentPtr& component);
};

#endif //SERRARIEN_HUD_HPP
