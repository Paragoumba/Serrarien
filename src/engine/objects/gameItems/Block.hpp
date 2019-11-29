#ifndef SERRARIEN_BLOCK_HPP
#define SERRARIEN_BLOCK_HPP

#include <map>

#include "GameItem.hpp"
#include "Variant.hpp"

enum BlockType {
    DIRT
};

class Block : public GameItem, public Variant<BlockType> {
private:
    static const GameItemType type = BLOCK;

public:
    explicit Block(BlockType _blockType);

    GameItemType getType() override;
    GameItemIdentifier getIdentifier() override;
};

typedef std::shared_ptr<Block> BlockPtr;

#endif //SERRARIEN_BLOCK_HPP
