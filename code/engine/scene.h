#pragma once

#include "engineVariables.h"

class Scene :public Eobject
{
    public:
        Scene() = default;
        virtual ~Scene() = default;

        virtual void events() =0;
        virtual void update() =0;
        virtual void draw() =0;
};
