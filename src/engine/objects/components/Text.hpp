#ifndef SERRARIEN_TEXT_HPP
#define SERRARIEN_TEXT_HPP

#include <string>

#include "Component.hpp"

class Text : public Component {
private:
    MeshPtr mesh;
    std::string text;

public:
    explicit Text(const char* text);

    MeshPtr& getMesh() override;
    std::string& getText();
    void setText(const char* _text);
};

typedef std::shared_ptr<Text> TextPtr;

#endif //SERRARIEN_TEXT_HPP
