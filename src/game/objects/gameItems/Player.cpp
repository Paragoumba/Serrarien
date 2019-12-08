#include "Player.hpp"

GameItemIdentifier Player::getIdentifier(){

    return GameItemIdentifier(getType(), 0);

}

GameItemType Player::getType(){

    return type;

}

