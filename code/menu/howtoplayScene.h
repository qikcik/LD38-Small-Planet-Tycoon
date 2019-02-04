#pragma once

#include "../engine/scene.h"
#include <SFML/Graphics.hpp>

class HowtoplayScene :public Scene
{
    public:
         HowtoplayScene();
        ~ HowtoplayScene();

        virtual void events();
        virtual void update();
        virtual void draw();

    private:
        sf::Sprite play;
};
