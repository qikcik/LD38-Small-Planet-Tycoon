#include "howtoplayScene.h"
#include "../game/gameScene.h"
#include "../resurce/textureMenager.h"

HowtoplayScene::HowtoplayScene()
{
    sf::View view;
    view.reset(sf::FloatRect(0, 0, 2572, 1528)); // skad
    //view.setSize( engine.WinWidth, engine.WinHeight); // gdzie
    engine.window.setView(view);
    play.setTexture(*TextureMenager::get().getTexture("instructions"));
}

HowtoplayScene::~HowtoplayScene()
{
    TextureMenager::get().deleteAllTexture();
}

void HowtoplayScene::events()
{

}

void HowtoplayScene::update()
{
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            engine.setScene( new GameScene);
        }
}

void HowtoplayScene::draw()
{
    engine.window.draw(play);
}

