#pragma once

#include "engineVariables.h"

class Layer :public Eobject
{
    public:
       Layer();
        ~Layer();

        virtual void events() = 0;
        virtual void update() = 0;
        void draw();

        sf::View view;
            virtual inline void drawWithoutView() = 0;
};
