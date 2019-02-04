#pragma once


#include <SFML/Graphics.hpp>
#include "engineVariables.h"

class Engine :public Eobject
{
    public:
        Engine();
        ~Engine();

        void run();

    private:
        void initWindow();

        void GameLoop();
            inline void events();
            inline void update();
            inline void draw();
};
