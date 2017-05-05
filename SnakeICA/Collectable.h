#ifndef COLLECTABLE_H
#define COLLECTABLE_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Collectable
{
    public:
        Collectable(std::string name, int score, int grow);
        virtual ~Collectable();
        void Render (sf::RenderWindow &window);
        sf::RectangleShape* getCollectable();
        bool isEaten();
        int addScore();
        int Eat();

    private:
        std::string c_name;
        sf::Vector2f c_pos{100,100};
        sf::RectangleShape c_obj;
        sf::Texture CTexture;
        int scoreadd{5};
        int growth{5};
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
