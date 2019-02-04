#include "Layer.h"

Layer::Layer()
{

}

Layer::~Layer()
{

}

void Layer::draw()
{
    engine.window.setView(view);
    drawWithoutView();

}
