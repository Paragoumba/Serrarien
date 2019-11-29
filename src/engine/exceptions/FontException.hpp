#ifndef SERRARIEN_FONTEXCEPTION_HPP
#define SERRARIEN_FONTEXCEPTION_HPP

#include "Exception.hpp"

class FontException : public Exception {
public:
    explicit FontException(const char* message) : Exception(message){};
};

#endif //SERRARIEN_FONTEXCEPTION_HPP
