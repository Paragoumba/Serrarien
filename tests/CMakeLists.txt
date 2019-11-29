add_executable(tests main.cpp ../src/engine/objects/components/Font.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest -lgtest_main")