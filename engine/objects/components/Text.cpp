#include "Text.hpp"
#include "../../../game/ResourcesManager.hpp"

Text::Text(const char* text){

    setText(text);

}

MeshPtr &Text::getMesh(){

    return mesh;

}

std::string& Text::getText(){

    return text;

}

void Text::setText(const char* _text){

    // TODO Implement REAL fonts
    // TODO Clean & optimize

    text = _text;

    int letterNumber = text.size();

    float vertices[letterNumber * 8];
    float texCoords[letterNumber * 8];
    unsigned int indices[letterNumber * 6];

    int fontBitmapWidth = ResourcesManager::getFontTexture()->getWidth();
    int fontBitmapHeight = ResourcesManager::getFontTexture()->getHeight();
    int charWidth = 10;
    int charHeight = 22;
    int colNumber = fontBitmapWidth / charWidth;
    //int rowNumber = fontBitmapHeight / 22;

    for (int i = 0; i < letterNumber; ++i){

        int letterVerticesNumber = i * 4;
        int letterPosition = text[i] - 32;

        vertices[letterVerticesNumber * 2]     = (float) (i * charWidth);
        vertices[letterVerticesNumber * 2 + 1] = 0.0f;
        vertices[letterVerticesNumber * 2 + 2] = (float) ((i + 1) * charWidth);
        vertices[letterVerticesNumber * 2 + 3] = 0.0f;
        vertices[letterVerticesNumber * 2 + 4] = (float) (i * charWidth);
        vertices[letterVerticesNumber * 2 + 5] = (float) charHeight;
        vertices[letterVerticesNumber * 2 + 6] = (float) ((i + 1) * charWidth);
        vertices[letterVerticesNumber * 2 + 7] = (float) charHeight;

        texCoords[letterVerticesNumber * 2]     = (float) (letterPosition % colNumber * charWidth) / (float) fontBitmapWidth;
        texCoords[letterVerticesNumber * 2 + 1] = 1 - (float) ((letterPosition / colNumber + 1) * charHeight) / (float) fontBitmapHeight; // NOLINT(bugprone-integer-division)
        texCoords[letterVerticesNumber * 2 + 2] = (float) ((letterPosition % colNumber + 1) * charWidth) / (float) fontBitmapWidth;
        texCoords[letterVerticesNumber * 2 + 3] = 1 - (float) ((letterPosition / colNumber + 1) * charHeight) / (float) fontBitmapHeight; // NOLINT(bugprone-integer-division)
        texCoords[letterVerticesNumber * 2 + 4] = (float) (letterPosition % colNumber * charWidth) / (float) fontBitmapWidth;
        texCoords[letterVerticesNumber * 2 + 5] = 1 - (float) (letterPosition / colNumber * charHeight) / (float) fontBitmapHeight; // NOLINT(bugprone-integer-division)
        texCoords[letterVerticesNumber * 2 + 6] = (float) ((letterPosition % colNumber + 1) * charWidth) / (float) fontBitmapWidth;
        texCoords[letterVerticesNumber * 2 + 7] = 1 - (float) (letterPosition / colNumber * charHeight) / (float) fontBitmapHeight; // NOLINT(bugprone-integer-division)

        indices[i * 6]     =     letterVerticesNumber;
        indices[i * 6 + 1] = 1 + letterVerticesNumber;
        indices[i * 6 + 2] = 2 + letterVerticesNumber;
        indices[i * 6 + 3] = 1 + letterVerticesNumber;
        indices[i * 6 + 4] = 3 + letterVerticesNumber;
        indices[i * 6 + 5] = 2 + letterVerticesNumber;

    }

    mesh = MeshPtr(new Mesh(vertices, sizeof(vertices), texCoords, sizeof(texCoords), indices, sizeof(indices)));

}
