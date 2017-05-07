#include "Collectable.h"
#include <SFML/Graphics.hpp>
#include "Snake.h"

Collectable::Collectable(std::string name, int score, int grow, sf::Texture&dir, int SpawnTimer):c_name(name), scoreadd(score), growth(grow), c_timer(SpawnTimer)
{
    c_obj.setSize(sf::Vector2f(20,20));
    //float rx = (rand() %(680/20)) * 20 + 40;
    //float ry = (rand() %(300/20)) * 20 + 40;
    c_pos.x = -20;
    c_pos.y = -20;
    c_obj.setPosition(c_pos);
    //if (!CTexture.loadFromFile("Textures/Arena.png"))
        //std::cout<<"Loading Apple Texture Failed"<<std::endl;
    //return EXIT_FAILURE;
    //CTexture.loadFromFile(dir);
    c_obj.setTexture(&dir,true);
    //ctor
}

Collectable::~Collectable()
{
    //dtor
}

void Collectable::CollectableInactive()
{
    c_pos.x = -20;
    c_pos.y = -20;
    c_obj.setPosition(c_pos);
}

void Collectable::Update()
{
    if(!isActive)
    {
        if(clock.getElapsedTime().asSeconds() > c_timer)
        {
            float rx = (rand() %(680/20)) * 20 + 40;
            float ry = (rand() %(300/20)) * 20 + 40;
            c_pos.x = rx;
            c_pos.y = ry;
            c_obj.setPosition(c_pos);
            isActive= true;
            eaten = false;
        }
    }
}

sf::RectangleShape* Collectable::getCollectable() //Return the Collectable Shape
{
    return &c_obj;
}

int Collectable::addScore() //Return the amount to add
{
   return scoreadd;
}

bool Collectable::isEaten() //Check if the collectable has been eaten
{
    return eaten;
}

int Collectable::Eat() //Eats the fruit and grow the amount specified, if its already been eaten, don't grow from it.
{
    if(!eaten)
    {
        eaten = true;
        isActive = false;
        clock.restart();
        return growth;
    }
    else
        return 0;

}

void Collectable::Render(sf::RenderWindow &window)
{
    if(isActive)
    {
    window.draw(c_obj);
    }
    //    c_obj.setTexture(&CTexture,true);
    //setColour();
}
