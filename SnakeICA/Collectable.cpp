#include "Collectable.h"
#include <SFML/Graphics.hpp>
#include "Snake.h"

Collectable::Collectable(std::string name):c_name(name)
{
    c_obj.setSize(sf::Vector2f(12,12));
    float rx = rand() %670 + 50;
    float ry = rand() %300 + 50;
    c_pos.x = rx;
    c_pos.y = ry;
    c_obj.setPosition(c_pos);
    if (!CTexture.loadFromFile("Textures/Apple.png"))
        //return EXIT_FAILURE;
    c_obj.setTexture(&CTexture,true);
    //ctor
}

Collectable::~Collectable()
{
    //dtor
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
