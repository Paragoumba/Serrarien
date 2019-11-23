#include "GameItem.hpp"
#include "../../../game/ResourcesManager.hpp"

MeshPtr &GameItem::getMesh(){

    return ResourcesManager::getMesh(this);

}
