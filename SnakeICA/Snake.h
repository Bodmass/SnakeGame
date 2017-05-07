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
        ///Init's Snake Constructor
        Snake(std::string name, sf::Texture& dir);
        Snake();
        virtual ~Snake();
        ///Render's Snake to the specified Render Window
        void Render (sf::RenderWindow &window);
        //sf::RectangleShape getHead();
        ///Snakes Update Function
        void Update();
        ///Sets the colour of the Snake
        void setColour();
        ///Sets the Direction of the snake (North, East, South, West)
        void setDirection(eDir dir);
        ///Returns the position of the snake's head
        sf::Vector2f getPos();
        ///Returns the snake's head
        sf::RectangleShape* getHead();
//        bool isDead();
        ///Increases the Player Score
        int addScore(int amount);
        ///Sets the death state of the snake
        void hasDied();
        ///Adds a segment to the snake
        void addSegment(unsigned int amount);
        ///Checks the collision with any of the Snake's Segments
        bool SegmentCollider();
        ///Return the score of the snake
        std::string getScore();
        ///Return the glue amount eaten by the snake
        std::string getGlue();
        ///Eat Glue
        int eatGlue(int amount);
        ///Use Glue
        void useGlue();


    protected:

    private:
        std::string s_name;
        ///Sets snake origin
        sf::Vector2f s_pos{400,300};
        ///Constructing the snake head
        sf::RectangleShape s_head;
        ///Setting movement speed (relative to snake size
        int snakespeed {20};
        ///Setting the clock and Collider clock (for snake spawn immunity to Segments)
        sf::Clock clock, colClock, gClock;
        ///eDir variable for direction
        eDir s_dir = eDir::eNorth;
        ///Snakes Score
        int s_score{0};
        ///Snakes Glue Amount
        int s_glue{0};
        ///Snake death state
        bool isDead = false;
        ///List of Segments
        sf::Texture m_texture;
        std::list<sf::RectangleShape*> Segments;
        ///Boolean for the Snake's Segment Immunity
        bool ColliderActive = false;
        ///Boolean to make sure the Segment Textures have loaded. Disable after Segment Immunity ends
        bool setinittextures = true;

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
