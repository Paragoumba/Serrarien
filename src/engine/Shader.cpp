#include "Shader.hpp"

Shader::Shader(const char* vertexPath, const char* fragmentPath){

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try {

        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();

    } catch (std::ifstream::failure& e){

        std::cout << "ERROR: Cannot read file." << std::endl;

    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    id = glCreateProgram();

    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);
    checkCompileErrors(id, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

void Shader::use(){

    glUseProgram(id);

}

void Shader::setBool(const char* name, bool value) const {

    glUniform1i(glGetUniformLocation(id, name), (int) value);

}

void Shader::setInt(const char* name, int value) const {

    glUniform1i(glGetUniformLocation(id, name), value);

}

void Shader::setFloat(const char* name, float value) const {

    glUniform1f(glGetUniformLocation(id, name), value);

}

void Shader::setMat4f(const char* name, glm::mat4 value) const {

    glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, glm::value_ptr(value));

}

void Shader::checkCompileErrors(unsigned int shader, const std::string& type){

    int success;
    char infoLog[1024];

    if (type != "PROGRAM"){

        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success){

            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "ERROR: Cannot compile shader (" << type << ") for the following reason:\n" << infoLog << std::endl;

        }

    } else {

        glGetProgramiv(shader, GL_LINK_STATUS, &success);

        if (!success){

            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "ERROR: Cannot link shader (" << type << ") for the following reason:\n" << infoLog << std::endl;

        }
    }
}

Shader::~Shader(){

    glUseProgram(0);
    glDeleteProgram(id);

}
