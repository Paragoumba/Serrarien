#include "Block.hpp"

Block::Block(BlockType _blockType) : Variant(){

    variant = _blockType;

}

GameItemIdentifier Block::getIdentifier(){

    return GameItemIdentifier(getType(), variant);

}

GameItemType Block::getType(){

    return type;

}
