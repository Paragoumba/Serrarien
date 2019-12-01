#ifndef SERRARIEN_SHADER_HPP
#define SERRARIEN_SHADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

class Shader {
public:
    unsigned int id;

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

    void use();

    void setBool(const char* name, bool value) const;
    void setInt(const char* name, int value) const;
    void setFloat(const char* name, float value) const;
    void setMat4f(const char* name, glm::mat4 value) const;

    ~Shader();

private:
    static void checkCompileErrors(unsigned int shader, const std::string& type);
};
#endif
