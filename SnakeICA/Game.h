#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Collectable.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
    public:
        ///Set's up the Snake Game
        Game(Snake& snake);
        ///Run the game
        void Run();
        virtual ~Game();
        ///Check if the game is still running
        bool isRunning = true;

    protected:

    private:
        ///Vector used for walls
        std::vector<sf::RectangleShape> Walls;
        ///Vector used for collectables
        std::vector<Collectable> Collectables;
        void processEvents();
        ///Update the game every frame
        void update();
        ///Render to the window
        void render();
        ///Create the game's UI (Score, Timer, Glue)
        void createUI();
        ///Update the game's UI
        void updateUI(sf::Texture BGTexture, sf::Sprite BG, sf::Text TimerText, sf::Text TimerTitle, sf::Text AISText, sf::Text PlayerScore, sf::Text PlayerSText, sf::Text GlueText);
        ///Create the window to render to
        sf::RenderWindow m_window;
        ///Create the player snake
        Snake & m_snake;
        ///Check the Collisions with the Snake and walls.
        bool CheckCollisions(Snake* snake);

};

#endif // GAME_H
