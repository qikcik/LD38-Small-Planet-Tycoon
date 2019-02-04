#pragma once

#include <SFML/Graphics.hpp>
#include <map>


//prototype

class TextureMenager // singleton
{

    // class
    public:

        sf::Font font;

        sf::Texture* getTexture(std::string name);
        void deleteTexture(std::string name);
        void deleteAllTexture();

    private:

        std::map <std::string , sf::Texture* > textureList;

    // singleton interface
    private:
        TextureMenager();
        TextureMenager( const TextureMenager & );
    public:
        static TextureMenager & get() { static TextureMenager s; return s; }
        ~TextureMenager();
};
