#include "HUD.hpp"

std::vector<ComponentPtr>& HUD::getComponents(){

    return components;

}

void HUD::addComponent(const ComponentPtr& component){

    components.push_back(component);

}
