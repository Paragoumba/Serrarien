#include "Camera.hpp"

Camera::Camera() : position(0, 0), rotation(0){}

glm::vec2 Camera::getPosition(){

    return position;

}

float Camera::getRotation(){

    return rotation;

}

void Camera::setPosition(float x, float y){

    position.x = x;
    position.y = y;

}

void Camera::setRotation(float deg){

    rotation = deg;

}

void Camera::translate(float x, float y){

    position.x += x;
    position.y += y;

}

void Camera::rotate(float deg){

    rotation = deg;

}

