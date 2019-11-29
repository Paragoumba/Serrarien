#ifndef SERRARIEN_PLAYER_HPP
#define SERRARIEN_PLAYER_HPP

#include "GameItem.hpp"

class Player : public GameItem {
private:
    static const GameItemType type = PLAYER;

public:
    GameItemType getType() override;
    GameItemIdentifier getIdentifier() override;
};

typedef std::shared_ptr<Player> PlayerPtr;

#endif //SERRARIEN_PLAYER_HPP
