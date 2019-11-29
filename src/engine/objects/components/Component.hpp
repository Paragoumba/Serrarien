#ifndef SERRARIEN_COMPONENT_HPP
#define SERRARIEN_COMPONENT_HPP

#include <memory>

#include "../Object.hpp"

/**
 * The class Component represents an object that can be rendered on the HUD.
 */
class Component : public Object {
};

typedef std::shared_ptr<Component> ComponentPtr;

#endif //SERRARIEN_COMPONENT_HPP
