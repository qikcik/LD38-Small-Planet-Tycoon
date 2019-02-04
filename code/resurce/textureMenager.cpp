#include "textureMenager.h"

TextureMenager::TextureMenager()
{
    font.loadFromFile("data/font.ttf");
}

TextureMenager::~TextureMenager()
{
    deleteAllTexture();
}

sf::Texture* TextureMenager::getTexture(std::string name)
{
    auto it = textureList.find(name);
    if (it != textureList.end())
       return it->second;

    textureList[name] = new sf::Texture;
    textureList[name]->loadFromFile("data/graphics/" +name + ".png");
    textureList[name]->setSmooth(true);
    textureList[name]->setRepeated(true);
        return textureList[name];
}

void TextureMenager::deleteTexture(std::string name)
{
    auto it = textureList.find(name);
    if (it != textureList.end())
    {
        delete it->second;
        textureList.erase(it);
    }
}

void TextureMenager::deleteAllTexture()
{
    for (auto it = textureList.begin() ; it != textureList.end() ; ++it)
        delete it->second;

    textureList.clear();
}


