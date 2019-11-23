#ifndef SERRARIEN_MESH_HPP
#define SERRARIEN_MESH_HPP

#include <vector>
#include <memory>

#include "Material.hpp"

class Mesh {
private:
    unsigned int vaoId{};
    std::vector<unsigned int> vboIds;
    int verticesNumber{};

public:
    Mesh(const float vertices[], unsigned long verticesNumber, const float texCoords[], unsigned long texCoordsNumber,
         const unsigned int indices[], unsigned long indicesNumber);

    void render() const;

    ~Mesh();
};

typedef std::shared_ptr<Mesh> MeshPtr;

#endif //SERRARIEN_MESH_HPP
