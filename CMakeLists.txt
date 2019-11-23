cmake_minimum_required(VERSION 3.0)
project(Serrarien)

set(CMAKE_CXX_STANDARD 17)

add_executable(Serrarien main.cpp lib/glad.c engine/Shader.cpp engine/Mesh.cpp engine/Texture.cpp engine/Material.cpp
        engine/objects/gameItems/GameItem.cpp engine/Camera.cpp game/Game.cpp engine/Renderer.cpp engine/Window.cpp
        engine/GameEngine.cpp engine/objects/gameItems/Block.cpp game/ResourcesManager.cpp
        engine/objects/gameItems/Player.cpp engine/HUD.cpp engine/objects/components/Component.cpp
        engine/objects/components/Item.cpp engine/objects/components/Text.cpp engine/objects/Object.cpp
        engine/Scene.cpp engine/Transformation.cpp engine/objects/gameItems/Disc.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglfw -lGL -ldl")