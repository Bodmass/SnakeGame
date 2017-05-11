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
    Snake(std::string name, sf::Texture& dir, sf::Vector2f spawnPos);
    Snake();
    virtual ~Snake();
    ///Render's Snake to the specified Render Window
    void Render (sf::RenderWindow &window);
    ///Reset the Snake back to how it started
    void Reset();
    ///Snakes Update Function
    void Update();
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
    ///Checks the death state
    bool checkDeath();
    ///Adds a segment to the snake
    void addSegment(unsigned int amount);
    ///Checks the collision with any of the Snake's Segments
    bool SegmentCollider();
    ///Return the string score of the snake
    std::string getScore();
    ///Return the integer score of the snake
    int getScoreI();
    ///Return the glue amount eaten by the snake
    std::string getGlue();
    ///Return the name of the snake (Used by the Win Scenario)
    std::string getName();
    ///Accumulate Glue
    int eatGlue(int amount);
    ///Use the glue and reset the glue clock
    void useGlue();
    ///Return the Segments List
    std::list<sf::RectangleShape*> getSegements();
    ///Hide the Snake for the gameover screen
    void goHide();
    ///get the Direction the snake is facing
    eDir getDirection();



protected:

private:
    std::string s_name;
    ///Sets snake origin
    sf::Vector2f s_pos{400,300};
    ///Constructing the snake head
    sf::RectangleShape s_head;
    ///Setting movement speed (relative to snake size
    int snakespeed {20};
    ///Setting the clock and Collider clock (for snake spawn immunity to Segments) and 2 glueClocks (to stop the snake momentarily and limit eating)
    sf::Clock clock, colClock, gClock, g2Clock;
    ///eDir variable for direction
    eDir s_dir = eDir::eNorth;
    ///Snakes Score
    int s_score{0};
    ///Snakes Glue Amount
    int s_glue{0};
    ///Snake death state
    bool isDead = false;
    ///Remember the spawn location used when using push_back for the snake.
    sf::Vector2f respawnPos;
    ///Texture for Segments
    sf::Texture m_texture;
    ///List of Segments
    std::list<sf::RectangleShape*> Segments;
    ///Boolean for the Snake's Segment Immunity
    bool ColliderActive = false;
    ///Boolean to make sure the Segment Textures have loaded. Disable after Segment Immunity ends
    bool setinittextures = true;
    ///Boolean to hide snake
    bool isHidden = false;

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
