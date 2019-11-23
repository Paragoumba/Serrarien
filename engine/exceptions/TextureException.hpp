#ifndef SERRARIEN_TEXTUREEXCEPTION_HPP
#define SERRARIEN_TEXTUREEXCEPTION_HPP

#include "Exception.hpp"

class TextureException : public Exception {
public:
    explicit TextureException(const char* message) : Exception(message){};
};

#endif //SERRARIEN_TEXTUREEXCEPTION_HPP
