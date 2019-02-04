#include "gameoverScene.h"
#include "menuScene.h"
#include "../resurce/textureMenager.h"

GameoverScene::GameoverScene()
{
    x = 0;
    engine.window.setView(engine.window.getDefaultView());
    play.setTexture(*TextureMenager::get().getTexture("planetExplosion"));
    play.setOrigin(sf::Vector2f(334,334));
    play.setPosition(sf::Vector2f(engine.WinWidth /2 ,engine.WinHeight /2 ));

    text.setFont(TextureMenager::get().font);

    text.setCharacterSize(24);
    text.setString("Your planet has been explosion");
    text.setOrigin( sf::Vector2f ( text.getGlobalBounds().width / 2 ,   text.getGlobalBounds().height / 2) );
    text.setPosition(sf::Vector2f(engine.WinWidth /2 - 10 ,engine.WinHeight /2 - 30 ));

}

GameoverScene::~GameoverScene()
{
    TextureMenager::get().deleteAllTexture();
}

void GameoverScene::events()
{

}

void GameoverScene::update()
{
    x += engine.delta;

    if (x > 3)
        engine.setScene(new MenuScene);
}

void GameoverScene::draw()
{
    engine.window.draw(play);
    engine.window.draw(text);
}

