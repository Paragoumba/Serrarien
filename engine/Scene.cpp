#include "Scene.hpp"

std::vector<GameItemPtr> &Scene::getGameItems(){

    return gameItems;

}

void Scene::addGameItem(const GameItemPtr& gameItem){

    gameItems.push_back(gameItem);

}
