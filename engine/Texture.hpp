#ifndef SERRARIEN_TEXTURE_HPP
#define SERRARIEN_TEXTURE_HPP

#include <string>

class Texture {
private:
    unsigned int textureId{};
    int width{};
    int height{};

public:
    explicit Texture(const char* path);

    [[nodiscard]] unsigned int getId() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

    ~Texture();
};

#endif //SERRARIEN_TEXTURE_HPP
