#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>

Snake::Snake(std::string name):s_name(name)
{
    std::cout<<s_name<<" constructed."<<std::endl;
    s_head.setSize(sf::Vector2f(16,16));
    s_head.setPosition(s_pos);
    setColour();

    //ctor
}

Snake::~Snake()
{
    //dtor
}

sf::Vector2f Snake::getPos()
{
    return s_pos;
}

std::string Snake::getScore()
{
    std::ostringstream showscore;
    long num = s_score;
    showscore << num;
    //std::string showscore = std::to_string(s_score);

    return showscore.str();
}

void Snake::setColour()
{
    srand(time(NULL));
    int iR=rand() % 155 + 100;
    int iG=rand() % 155 + 100;
    int iB=rand() % 155 + 100;

    s_head.setFillColor(sf::Color(iR,iG,iB,255));
}

void Snake::setDirection(eDir dir)
{
    s_dir = dir;
}


void Snake::Update()
{
    //std::cout<<clock.getElapsedTime().asMilliseconds();
//    if(isDead() == false)
    if(isDead == false)
    {
        if(clock.getElapsedTime().asMilliseconds() > 100){
            if (s_dir == eDir::eWest)
                s_pos.x+=snakespeed;
            else if (s_dir == eDir::eEast)
                s_pos.x-=snakespeed;
            else if (s_dir == eDir::eNorth)
                s_pos.y-=snakespeed;
            else if (s_dir == eDir::eSouth)
                s_pos.y+=snakespeed;
            clock.restart();
        }

    s_head.setPosition(s_pos);
    }
}

void Snake::hasDied()
{
    isDead = true;
}

//bool Snake::isDead()
//{
//    std::cout<<"Snake died";
//    return true;
//}

//sf::RectangleShape Snake::getHead()
//{
//return Snake::s_head;
//}

void Snake::Render(sf::RenderWindow &window)
{
    window.draw(s_head);
    //setColour();
}
