#include "ResourcesManager.hpp"
#include "../engine/objects/gameItems/Block.hpp"

std::map<GameItemType, MeshPtr> ResourcesManager::meshes;
std::map<GameItemIdentifier, MaterialPtr> ResourcesManager::materials;
Texture* ResourcesManager::fontBitmap;

void ResourcesManager::init(){

    fontBitmap = new Texture("../res/images/fonts/NotoSansMonoLight.png");

    /* DirtBlock */
    float blockVertices[] = {
            0.0f, 0.0f, // Top left
            16.0f, 0.0f, // Top right
            0.0f, 16.0f, // Bottom left
            16.0f, 16.0f  // Bottom right
    };

    float blockTexCoords[] = {
            0.0f, 0.0f, // Top left
            1.0f, 0.0f, // Top right
            0.0f, 1.0f, // Bottom left
            1.0f, 1.0f  // Bottom right
    };

    unsigned int blockIndices[] = {
            0, 1, 2,
            1, 3, 2
    };

    MeshPtr blockMesh(new Mesh(
            blockVertices, sizeof(blockVertices),
            blockTexCoords, sizeof(blockTexCoords),
            blockIndices, sizeof(blockIndices)));

    meshes.insert(std::make_pair(BLOCK, blockMesh));

    MaterialPtr dirtBlockMaterial(new Material());

    auto dirtBlockTexture = new Texture("../res/images/blocks/dirt.png");

    dirtBlockMaterial->addTexture(dirtBlockTexture);

    materials[GameItemIdentifier(BLOCK, DIRT)] = dirtBlockMaterial;

    /* Snowman */
    float playerVertices[] = {
            0.0f, 0.0f, // Top left
            16.0f, 0.0f, // Top right
            0.0f, 32.0f, // Bottom left
            16.0f, 32.0f  // Bottom right
    };

    float playerTexCoords[] = {
            0.0f, 0.0f, // Top left
            1.0f, 0.0f, // Top right
            0.0f, 1.0f, // Bottom left
            1.0f, 1.0f  // Bottom right
    };

    unsigned int playerIndices[] = {
            0, 1, 2,
            1, 3, 2
    };

    MeshPtr playerMesh(new Mesh(
            playerVertices, sizeof(playerVertices),
            playerTexCoords, sizeof(playerTexCoords),
            playerIndices, sizeof(playerIndices)));

    meshes.insert(std::make_pair(PLAYER, playerMesh));

    MaterialPtr playerMaterial(new Material);

    auto playerTexture = new Texture("../res/images/entities/snowman/right.png");

    playerMaterial->addTexture(playerTexture);

    materials[GameItemIdentifier(PLAYER, 0)] = playerMaterial;

    makeDisc(63);

}

MaterialPtr& ResourcesManager::getMaterial(GameItem* object){

    return materials[object->getIdentifier()];

}

Texture* ResourcesManager::getFontTexture(){

    return fontBitmap;

}

MeshPtr& ResourcesManager::getMesh(GameItem* gameItem){

    return meshes[gameItem->getType()];

}

void ResourcesManager::makeDisc(int resolution){

    float discVertices[resolution * 2 * 3];

    float discTexCoords[resolution * 2];

    unsigned int discIndices[resolution * 3];

    int j = 0;

    for (int i = 0; i < resolution; ++i){

        float alpha = 360.0f / (float) resolution;

        discVertices[j] = std::cos(glm::radians(alpha * (float) i)) * 10;
        discVertices[j + 1] = std::sin(glm::radians(alpha * (float) i)) * 10;
        discVertices[j + 2] = std::cos(glm::radians(alpha * (float) i + 1)) * 10;
        discVertices[j + 3] = std::sin(glm::radians(alpha * (float) i + 1)) * 10;
        discVertices[j + 4] = 0;
        discVertices[j + 5] = 0;
        discIndices[j] = j;
        discIndices[j + 1] = j + 1;
        discIndices[j + 2] = j + 2;

        discTexCoords[j] = 0;
        discTexCoords[j + 1] = 1;

        j += 5;

    }

    MeshPtr disc(new Mesh(
            discVertices, sizeof(discVertices),
            discTexCoords, sizeof(discTexCoords),
            discIndices, sizeof(discIndices)));

    meshes[DISC] = disc;

    auto playerTexture = new Texture("../res/images/entities/snowman/right.png");

    MaterialPtr discMaterial(new Material());

    discMaterial->addTexture(playerTexture);

    materials[GameItemIdentifier(DISC, 0)] = discMaterial;

}
