#define STB_IMAGE_IMPLEMENTATION

#include <stb/stb_image.h>
#include <cstdlib>

#include "engine/GameEngine.hpp"
#include "engine/exceptions/InitException.hpp"

int main(){

    try {

        GameEngine engine;

        engine.loop();

    } catch (InitException& e){

        std::cout << e.what() << std::endl;

    }

    return EXIT_SUCCESS;

}