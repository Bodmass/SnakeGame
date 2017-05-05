#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <list>

enum class eDir
{
    eNorth,
    eEast,
    eSouth,
    eWest
};


class Snake
{
    public:
        Snake(std::string name);
        virtual ~Snake();
        void Render (sf::RenderWindow &window);
        //sf::RectangleShape getHead();
        void Update();
        void setColour();
        void setDirection(eDir dir);
        sf::Vector2f getPos();
        sf::RectangleShape* getHead();
//        bool isDead();
        void hasDied();
        void addSegment(unsigned int amount);
        bool SegmentCollider();
        std::string getScore();


    protected:

    private:
        std::string s_name;
        sf::Vector2f s_pos{400,300};
        sf::RectangleShape s_head;
        int const snakespeed {20};
        sf::Clock clock, colClock;
        eDir s_dir = eDir::eNorth;
        int s_score{0};
        int s_glue{0};
        bool isDead = false;
        std::list<sf::RectangleShape*> Segments;
        bool ColliderActive = false;

};

/*
NOTES::

-Add Glue
-Add Fragments
-Player Inheritence
-Snake AI
-Change from Vector2f to Vector2i
*/

#endif // SNAKE_H
