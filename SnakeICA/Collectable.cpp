#include "Collectable.h"
#include <SFML/Graphics.hpp>
#include "Snake.h"

Collectable::Collectable(std::string name, int score, int grow):c_name(name), scoreadd(score), growth(grow)
{
    c_obj.setSize(sf::Vector2f(20,20));
    float rx = (rand() %(680/20)) * 20 + 40;
    float ry = (rand() %(300/20)) * 20 + 40;
    c_pos.x = rx;
    c_pos.y = ry;
    c_obj.setPosition(c_pos);
    if (!CTexture.loadFromFile("Textures/Arena.png"))
        std::cout<<"Loading Apple Texture Failed"<<std::endl;
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

bool Collectable::isEaten()
{
    return eaten;
}

int Collectable::Eat()
{
    if(!eaten)
    {
        eaten = true;
        return growth;
    }
    else
        return 0;

}

void Collectable::Render(sf::RenderWindow &window)
{
    window.draw(c_obj);
    //setColour();
}
