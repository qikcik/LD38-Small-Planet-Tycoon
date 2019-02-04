#include "gameScene.h"
#include "../resurce/textureMenager.h"

GameScene::GameScene() :
    gameplayLayer()
{

}

GameScene::~GameScene()
{
    TextureMenager::get().deleteAllTexture();
}

void GameScene::events()
{
    guiRightLayer.events();
}

void GameScene::update()
{
    gameplayLayer.update();
    guiLeftLayer.update();
    guiRightLayer.update();
    iconInfo.update();
    logic.update();

}

void GameScene::draw()
{
    gameplayLayer.draw();
    guiLeftLayer.draw();
    guiRightLayer.draw();
    iconInfo.draw();

}

