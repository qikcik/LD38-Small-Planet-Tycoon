#pragma once

#include "../engine/scene.h"
#include "gameplay/gameplayLayer.h"
#include "gui/guiLeftLayer.h"
#include "gui/guiRightLayer.h"
#include "logic.h"
#include "gui/iconInfo.h"

class GameScene :public Scene
{
    public:
        GameScene();
        ~GameScene();

        virtual void events();
        virtual void update();
        virtual void draw();

        GameplayLayer gameplayLayer;
        GuiRightLayer  guiRightLayer;
        GuiLeftLayer  guiLeftLayer;
        Logic logic;
        IconInfo iconInfo;

};
