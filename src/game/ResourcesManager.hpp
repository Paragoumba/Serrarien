#ifndef SERRARIEN_RESOURCESMANAGER_HPP
#define SERRARIEN_RESOURCESMANAGER_HPP

#include <map>

#include "../engine/Mesh.hpp"
#include "../engine/objects/gameItems/GameItem.hpp"
#include "objects/gameItems/Variant.hpp"

class ResourcesManager {
private:
    static std::map<GameItemType, MeshPtr> meshes;
    static std::map<GameItemIdentifier, MaterialPtr> materials;
    static Texture* fontBitmap;

    static void makeDisc(int resolution);

public:
    ResourcesManager() = delete;

    static void init();
    static MeshPtr& getMesh(GameItem* gameItem);
    static MaterialPtr& getMaterial(GameItem* gameItem);
    static Texture* getFontTexture();
};

#endif //SERRARIEN_RESOURCESMANAGER_HPP
