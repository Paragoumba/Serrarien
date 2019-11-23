#ifndef SERRARIEN_EXCEPTION_HPP
#define SERRARIEN_EXCEPTION_HPP

#include <exception>

class Exception : std::exception {
private:
    const char* message;

public:
    explicit Exception(const char* _message){

        message = _message;

    }

    virtual const char* what(){

        return message;

    }
};

#endif //SERRARIEN_EXCEPTION_HPP
