#ifndef SERRARIEN_MATERIAL_HPP
#define SERRARIEN_MATERIAL_HPP

#include <vector>
#include <memory>

#include "Texture.hpp"

class Material {
private:
    std::vector<Texture*> textures;

public:
    void addTexture(Texture* texture);
    void use();

    ~Material();
};

typedef std::shared_ptr<Material> MaterialPtr;

#endif //SERRARIEN_MATERIAL_HPP
