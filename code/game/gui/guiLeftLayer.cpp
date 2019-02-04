#include "guiLeftLayer.h"
#include "../../resurce/textureMenager.h"

GuiLeftLayer::GuiLeftLayer()
{
    view.reset(sf::FloatRect(0, 0, engine.WinWidth, engine.WinHeight)); // skad
    view.setSize(1.0f * engine.WinWidth, 1.0f * engine.WinHeight); // gdzie

    for(int i = 0 ; i != infoLabelSize ; i++)
    {
        infoLabel[i].setPosition(sf::Vector2f(5,10 + (i * 100) ) );
        infoLabel[i].setTexture(engine.toString (i + 1));
    }
}

GuiLeftLayer::~GuiLeftLayer()
{

}

void GuiLeftLayer::events()
{

}

void GuiLeftLayer::update()
{
    for(int i = 0 ; i != infoLabelSize ; i++)
        infoLabel[i].update();
}

void GuiLeftLayer::drawWithoutView()
{
    for(int i = 0 ; i != infoLabelSize ; i++)
        infoLabel[i].draw();
}
