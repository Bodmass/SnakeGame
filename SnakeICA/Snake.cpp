#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>

Snake::Snake(std::string name, sf::Texture& dir, sf::Vector2f spawnPos):s_name(name), s_pos(spawnPos)
{
    std::cout<<s_name<<" constructed."<<std::endl;
    s_head.setSize(sf::Vector2f(20,20));
    s_head.setPosition(s_pos);
    //s_head.setFillColor(sf::Color::Red);
    s_head.setTexture(&dir,true);
    m_texture = dir;
    addSegment(4); //Start the snake with a few segments
    //setColour();

    //ctor
}


Snake::Snake()
{

}

Snake::~Snake()
{
    //dtor
}

sf::Vector2f Snake::getPos() //Return the position of the snake
{
    return s_pos;
}

int Snake::addScore(int amount) //adds score to the snake
{
    s_score+=amount;
}

std::string Snake::getScore() //Returns the Score into a string
{
    std::ostringstream showscore;
    long num = s_score;
    showscore << num;
    //std::string showscore = std::to_string(s_score);

    return showscore.str();
}

std::string Snake::getGlue() //Returns the Score into a string
{
    std::ostringstream showglue;
    if(s_glue != 100)
    {
        long num = s_glue;
        showglue << num;
        showglue << "%";
    }
    else
        showglue << "READY";
    return showglue.str();
}

void Snake::setColour() //Sets random colour for RGB (Currently Unused)
{
    srand(time(NULL));
    int iR=rand() % 155 + 100;
    int iG=rand() % 155 + 100;
    int iB=rand() % 155 + 100;

#ifdef OS_Windows // This is a test
    s_head.setFillColor(sf::Color(iR,iG,iB,255));
#else
    s_head.setFillColor(sf::Color(iR,iG,iB,255));
#endif
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
        setinittextures = false;
    }
    //std::cout<<clock.getElapsedTime().asMilliseconds();
//    if(isDead() == false)
    if(!isDead)
    {
        SegmentCollider();

        if(gClock.getElapsedTime().asSeconds() > 1)
        {
            if(clock.getElapsedTime().asMilliseconds() > 100)  //Delay the Update every 100 milliseconds
            {
                sf::Vector2f oldpos = s_pos; //Use this variable to remember the position to move to
                sf::Vector2f oldsegpos; //Use this variable to remember the next segment to move to
                bool movefirst = false;
                for(sf::RectangleShape* Snake:Segments) //Loop for each segment
                {
                    //oldsegpos = Snake->getPosition();
                    if(!movefirst) //If the first segment hasnt moved first
                    {
                        oldsegpos = oldpos;
                        Snake->setPosition(oldpos); //Move the segment to the heads old position
                        movefirst = true;
                    }
                    else
                    {
                        sf::Vector2f tmp = Snake->getPosition(); //for each following, set the segment pos as the one ahead of it
                        Snake->setPosition(oldsegpos);
                        oldsegpos = tmp;
                    }
                } //Now move the snake to be ahead of the segments
                //Move the snake in the direction set
                if (s_dir == eDir::eWest)
                    s_pos.x+=snakespeed;
                else if (s_dir == eDir::eEast)
                    s_pos.x-=snakespeed;
                else if (s_dir == eDir::eNorth)
                    s_pos.y-=snakespeed;
                else if (s_dir == eDir::eSouth)
                    s_pos.y+=snakespeed;
                clock.restart(); //Reset the clock
            }
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
    if(!isDead)
    {
        if(!amount)  //If theres nothing in the amount to add, just stop running this function
        {
            return;
        }
        std::cout<<"Segments left"<<amount<<std::endl; //TEMP:: Print out the amount left to segment by
        amount--; //reduce amount left to increase by
        addSegment(amount); //Run this function again so it can loop and add any segments which are left
        sf::RectangleShape* Segment = new sf::RectangleShape(sf::Vector2f(20,20));
        //Segment->setFillColor(sf::Color::Red);
        Segment->setTexture(&m_texture,true);
        Segment->setPosition(sf::Vector2f(-20,-20)); //hide out of bounds until spawned onto snake

        Segments.push_back(Segment); //adds segments to the list
    }
}

int Snake::eatGlue(int amount)
{
    if(!isDead)
    {

        if(g2Clock.getElapsedTime().asMilliseconds() > 50)  //Delay the amount you can eat to only once every 50 milliseconds
        {
            if(s_glue<= 100)
                s_glue+=amount;
            if(s_glue>100)
                s_glue=100;
            g2Clock.restart();
        }
    }
    return 0;
}

void Snake::useGlue()
{
    if(!isDead)
    {
        if(s_glue<100)
        {
            return;
        }
        if(s_glue>=100)
        {
            s_glue = 0;
            gClock.restart();
        }
    }
}

void Snake::hasDied()
{
    if(!isDead)
    {
        isDead = true;
        std::cout<<s_name<<" has died!"<<std::endl;
    }
}

std::list<sf::RectangleShape*> Snake::getSegements()
{
    return Segments;
}

bool Snake::checkDeath() {return isDead;}

bool Snake::SegmentCollider() //Sets up the colliders for the snakes own segments
{
    if(ColliderActive) //Boolean to create few moments of immunity when the snake spawns in
    {
        for(sf::RectangleShape* Shape:Segments) //Loop through the Segments List
        {
            if(this->getHead()->getGlobalBounds().intersects(Shape->getGlobalBounds())) //if the head intersects of the of segments
            {
                this->hasDied(); //sets death state
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

    if(setinittextures)
    {
        for(sf::RectangleShape* Shape:Segments) //Loop through the Segments List
        {
            Shape->setTexture(&m_texture,true);
            //std::cout<<"Setting Textures"<<std::endl;
        }
    }

    for(sf::RectangleShape* Snake:Segments)
    {
        window.draw(*Snake);
    }
    //setColour();
}
