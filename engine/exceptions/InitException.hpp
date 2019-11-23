#ifndef SERRARIEN_INITEXCEPTION_HPP
#define SERRARIEN_INITEXCEPTION_HPP

#include "Exception.hpp"

class InitException : public Exception {
public:
    explicit InitException(const char* message) : Exception(message){};
};

#endif //SERRARIEN_INITEXCEPTION_HPP
