#include "engineVariables.h"

EngineVariables::EngineVariables() :
    WinWidth(1440),
    WinHeight(800),
    isFullscreen(false),
    isVsync(false),
    delta(1.f /60),
    antialiasingLevel(8)
{
    scene = nullptr;
}


EngineVariables::~EngineVariables()
{
    if (scene != nullptr)
        delete scene;
}

void EngineVariables::updateWindow()
{
    window.create(sf::VideoMode(WinWidth, WinHeight) , title);
}

Scene* EngineVariables::setScene(Scene* newScene)
{
    if (scene != nullptr)
        delete scene;

    scene =  newScene;
    return scene;
}

Scene* EngineVariables::getScene()
{
    return scene;
}

std::string EngineVariables::toString(float number)
{
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}
