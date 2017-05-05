#include "Collectable.h"
#include <SFML/Graphics.hpp>
#include "Snake.h"

Collectable::Collectable(std::string name):c_name(name)
{
    c_obj.setSize(sf::Vector2f(20,20));
    float rx = rand() %680 + 40;
    float ry = rand() %300 + 40;
    c_pos.x = rx;
    c_pos.y = ry;
    c_obj.setPosition(c_pos);
    if (!CTexture.loadFromFile("Textures/Arena.png"))
        std::cout<<"Loaded Apple Texture"<<std::endl;
        //return EXIT_FAILURE;
    c_obj.setTexture(&CTexture,true);
    //ctor
}

Collectable::~Collectable()
{
    //dtor
}

sf::RectangleShape* Collectable::getCollectable()
{
    return &c_obj;
}

int Collectable::addScore()
{
   return scoreadd;
}

void Collectable::Render(sf::RenderWindow &window)
{
    window.draw(c_obj);
    //setColour();
}
