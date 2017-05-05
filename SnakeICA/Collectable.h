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
        Collectable(std::string name, int score, int grow);
        virtual ~Collectable();
        void Render (sf::RenderWindow &window);
        ///Return the collectable shape
        sf::RectangleShape* getCollectable();
        ///Return if the collectable has been eaten
        bool isEaten();
        ///Returns the amount to add to the score
        int addScore();
        ///Eats the collectable
        int Eat();

    private:
        std::string c_name;
        sf::Vector2f c_pos{100,100};
        sf::RectangleShape c_obj;
        ///Texture for the Collectable (WIP)
        sf::Texture CTexture;
        ///Amount to increase score
        int scoreadd{5};
        ///Amount to segment snake by
        int growth{5};
        ///Boolean used for the eaten state
        bool eaten = false;
};

/*
NOTES::

-Add Texture (get it working)
-Add to the Score
-Add Fragments to Snake
-Make Position Random

*/

#endif // COLLECTABLE_H
