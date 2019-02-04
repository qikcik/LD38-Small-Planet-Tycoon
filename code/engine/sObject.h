#pragma once

#include "engineVariables.h"
#include "../resurce/textureMenager.h"

class Sobject  :public Eobject
{
    public:
        virtual void update() =0;
        virtual void draw() =0;
};

