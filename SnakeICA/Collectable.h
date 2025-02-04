#ifndef COLLECTABLE_H
#define COLLECTABLE_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Collectable
{
    public:
        ///Initialiser for Collectable to take a name, amount to add to score and amount to grow.
        Collectable(std::string name, int score, int grow, sf::Texture&dir, int SpawnTimer = 5);
        virtual ~Collectable();
        void Render (sf::RenderWindow &window);
        ///Collectable Update Function
        void Update();
        ///Return the collectable shape
        sf::RectangleShape* getCollectable();
        ///Return if the collectable has been eaten
        bool isEaten();
        ///Returns the amount to add to the score
        int addScore();
        ///Eats the collectable (virtual so the glue can be affected differently)
        virtual int Eat();
        ///Function to hide collectable off screen until its ready.
        void CollectableInactive();
        ///Randomize a position of the collectable to respawn it
        sf::Vector2f RandPos();
        ///Move the Collectable to a Specified Position (used for respawning)
        void CollectableMove(sf::Vector2f);
        ///Check if the Collectable is active in the scene
        bool CheckActive();

    protected:
        sf::RectangleShape c_obj;
    private:
        std::string c_name;
        sf::Vector2f c_pos{100,100};
        ///Amount to increase score
        int scoreadd{5};
        ///Amount to segment snake by
        int growth{5};
        ///Time it takes to spawn the Collectable
        int c_timer{5};
        ///Clock used for (re)spawning
        sf::Clock clock;
        ///Boolean used for the eaten state
        bool eaten = true;
        ///Boolean used to see if the Collectable is active
        bool isActive = false;



};


class Glue : public Collectable //Inherit from the Collectable (Having issues)
{
    public:
        Glue(std::string name, int score, int grow, sf::Texture&dir, int SpawnTimer = 5);
        ~Glue();
        //Glue();
        /// A twist from the Collectable Eat to not actually consume the glue
        int Eat();
        ///Add Glue while inside snake is inside
        int addGlue();

    private:
        ///Fixed variable for how much glue you should accumulate every 50 milliseconds
        int glueamount{2};

};
/*
NOTES::

-Add Glue

*/

#endif // COLLECTABLE_H
