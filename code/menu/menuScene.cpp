#include "menuScene.h"
#include "../game/gameScene.h"
#include "howtoplayScene.h"
#include "../resurce/textureMenager.h"

MenuScene::MenuScene()
{
    engine.window.setView(engine.window.getDefaultView());
    play.setTexture(*TextureMenager::get().getTexture("planet"));
    play.setOrigin(sf::Vector2f(334,334));
    play.setPosition(sf::Vector2f(engine.WinWidth /2 ,engine.WinHeight /2 ));

    text[0].setFont(TextureMenager::get().font);
    text[1].setFont(TextureMenager::get().font);
    text[2].setFont(TextureMenager::get().font);

    text[0].setCharacterSize(100);
    text[0].setString("Play");
    text[0].setOrigin( sf::Vector2f ( text[0].getGlobalBounds().width / 2 ,   text[0].getGlobalBounds().height / 2) );
    text[0].setPosition(sf::Vector2f(engine.WinWidth /2 - 10 ,engine.WinHeight /2 - 30 ));

    text[2].setCharacterSize(18);
    text[2].setString("created by Qikcik(Querk) for ludum dare 38 using font Averia Sans Libre");
    text[2].setPosition( sf::Vector2f ( engine.WinWidth - text[2].getGlobalBounds().width   - 10,
                                                    engine.WinHeight - text[2].getGlobalBounds().height  - 10) );

    text[2].setCharacterSize(28);
    text[2].setString("How To Play");
    text[2].setPosition( sf::Vector2f ( 10 ,10) );
}

MenuScene::~MenuScene()
{
    TextureMenager::get().deleteAllTexture();
}

void MenuScene::events()
{

}

void MenuScene::update()
{
    play.rotate(2 * engine.delta);

    sf::Vector2f mouse( engine.window.mapPixelToCoords(sf::Mouse::getPosition(engine.window) ));
    if(text[0].getGlobalBounds().contains(mouse) )
    {
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            engine.setScene( new GameScene);
        }
   }
    if(text[2].getGlobalBounds().contains(mouse) )
    {
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            engine.setScene( new HowtoplayScene );
        }
   }
}

void MenuScene::draw()
{
    engine.window.draw(play);
    engine.window.draw(text[0]);
    engine.window.draw(text[1]);
    engine.window.draw(text[2]);
}

