#include "Object.hpp"

Object::Object() : position(0, 0), scale(1, 1), rotation(0){}

glm::vec2 Object::getPosition() const {

    return position;

}

glm::vec2 Object::getScale() const {

    return scale;

}

float Object::getRotation() const {

    return rotation;

}

void Object::setPosition(float x, float y){

    position.x = x;
    position.y = y;

}

void Object::setScale(float x, float y){

    scale.x = x;
    scale.y = y;

}

void Object::setScale(float _scale){

    scale.x = scale.y = _scale;

}

void Object::setRotation(float deg){

    rotation = deg;

}

void Object::translate(float x, float y){

    position.x += x;
    position.y += y;

}

void Object::rotate(float deg){

    rotation += deg;

}

void Object::addScale(float scaleX, float scaleY){

    scale.x += scaleX;
    scale.y += scaleY;

}

void Object::addScale(float _scale){

    scale += _scale;

}
