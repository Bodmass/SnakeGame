#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>

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
//        bool isDead();
        void hasDied();
        std::string getScore();


    protected:

    private:
        std::string s_name;
        sf::Vector2f s_pos{400,300};
        sf::RectangleShape s_head;
        int const snakespeed {16};
        sf::Clock clock;
        eDir s_dir = eDir::eNorth;
        int s_score{0};
        int s_glue{0};
        bool isDead = false;

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
