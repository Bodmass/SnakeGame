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
    s_head.setSize(sf::Vector2f(20,20));
    s_head.setPosition(s_pos);
     s_head.setFillColor(sf::Color::Red);
     addSegment(4);

    //setColour();

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
    if(colClock.getElapsedTime().asSeconds() > 3)
    {
        ColliderActive = true;
    }
    //std::cout<<clock.getElapsedTime().asMilliseconds();
//    if(isDead() == false)
    if(!isDead)
    {
        SegmentCollider();


        if(clock.getElapsedTime().asMilliseconds() > 100){
            sf::Vector2f oldpos = s_pos;
            sf::Vector2f oldsegpos;
            bool movefirst = false;
            for(sf::RectangleShape* Snake:Segments)
            {
                //oldsegpos = Snake->getPosition();
                if(!movefirst)
                {
                    oldsegpos = oldpos;
                    Snake->setPosition(oldpos);
                    movefirst = true;
                }
                else
                {
                    sf::Vector2f tmp = Snake->getPosition();
                    Snake->setPosition(oldsegpos);
                    oldsegpos = tmp;
                }
            }
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

sf::RectangleShape* Snake::getHead()
{
    return &s_head;
}

void Snake::addSegment(unsigned int amount)
{
    if(!amount){
        return;
    }
    std::cout<<"Segments left"<<amount<<std::endl;
    amount--;
    addSegment(amount);
    sf::RectangleShape* Segment = new sf::RectangleShape(sf::Vector2f(20,20));
    Segment->setFillColor(sf::Color::Red);
    Segments.push_back(Segment);
}

void Snake::hasDied()
{
    isDead = true;
}

bool Snake::SegmentCollider()
{
    if(ColliderActive)
    {
        for(sf::RectangleShape* Shape:Segments)
        {
            if(this->getHead()->getGlobalBounds().intersects(Shape->getGlobalBounds()))
            {
                this->hasDied();
                return true;
            }
        }
    }
    return false;
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
    for(sf::RectangleShape* Snake:Segments)
    {
        window.draw(*Snake);
    }
    //setColour();
}
