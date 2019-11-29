#include <glad/glad.h>

#include "Mesh.hpp"

Mesh::Mesh(const float* vertices, unsigned long verticesNumber, const float texCoords[], unsigned long texCoordsNumber,
        const unsigned int* indices, unsigned long indicesNumber){

    this->verticesNumber = indicesNumber / sizeof(indices[0]); // NOLINT(bugprone-narrowing-conversions,
                                                                  // cppcoreguidelines-narrowing-conversions)

    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);

    unsigned int vboId;

    glGenBuffers(1, &vboId);
    vboIds.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, verticesNumber, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &vboId);
    vboIds.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, texCoordsNumber, texCoords, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &vboId);
    vboIds.push_back(vboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesNumber, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Mesh::render() const {

    glBindVertexArray(vaoId);
    glDrawElements(GL_TRIANGLES, verticesNumber, GL_UNSIGNED_INT, nullptr);

}

Mesh::~Mesh(){

    // Delete the VBOs
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(vboIds.size(), &vboIds[0]);

    // Delete the VAO
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vaoId);

}