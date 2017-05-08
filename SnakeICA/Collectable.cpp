#include "Collectable.h"
#include <SFML/Graphics.hpp>
#include "Snake.h"

Collectable::Collectable(std::string name, int score, int grow, sf::Texture&dir, int SpawnTimer):c_name(name), scoreadd(score), growth(grow), c_timer(SpawnTimer)
{
    c_obj.setSize(sf::Vector2f(20,20));
    //float rx = (rand() %(680/20)) * 20 + 40;
    //float ry = (rand() %(300/20)) * 20 + 40;
    c_pos.x = -40;
    c_pos.y = -40;
    c_obj.setPosition(c_pos);
    //if (!CTexture.loadFromFile("Textures/Arena.png"))
    //std::cout<<"Loading Apple Texture Failed"<<std::endl;
    //return EXIT_FAILURE;
    //CTexture.loadFromFile(dir);
    c_obj.setTexture(&dir,true);
    //ctor
}

Glue::Glue(std::string name, int score, int grow, sf::Texture&dir, int SpawnTimer):Collectable(name, score, grow, dir, SpawnTimer)
{
    c_obj.setSize(sf::Vector2f(40,40));
}

Glue::~Glue()
{
    //dtor
}


Collectable::~Collectable()
{
    //dtor
}

void Collectable::CollectableInactive()
{
    c_pos.x = -40;
    c_pos.y = -40;
    c_obj.setPosition(c_pos);
}

sf::Vector2f Collectable::RandPos()
{
    float rx = (rand() %(680/20)) * 20 + 40;
    float ry = (rand() %(300/20)) * 20 + 40;
    sf::Vector2f newpos{rx,ry};
    return newpos;
}

bool Collectable::CheckActive()
{
    if(isActive)
        return true;
    return false;
}

void Collectable::CollectableMove(sf::Vector2f(position))
{

}

void Collectable::Update()
{
    if(!isActive)
    {
        if(clock.getElapsedTime().asSeconds() > c_timer)
        {
            c_obj.setPosition(RandPos());
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

int Glue::Eat() //Eats the fruit and grow the amount specified, if its already been eaten, don't grow from it.
{
    return 0;
}

int Glue::addGlue()
{
    return glueamount;
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
