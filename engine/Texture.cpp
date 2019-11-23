#include <glad/glad.h>
#include <stb/stb_image.h>
#include <iostream>

#include "Texture.hpp"

Texture::Texture(const char* path){

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int nrChannels;

    // load image, create texture and generate mipmaps
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

    if (data){

        glTexImage2D(GL_TEXTURE_2D, 0, nrChannels == 4 ? GL_RGBA : GL_RGB, width, height, 0,
                nrChannels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

    } else {

        std::cerr << "Failed to load texture." << std::endl;

    }

    stbi_image_free(data);

}

unsigned int Texture::getId() const {

    return textureId;

}

int Texture::getWidth() const {

    return width;

}

int Texture::getHeight() const {

    return height;

}

Texture::~Texture(){

    glDeleteTextures(1, &textureId);

}
