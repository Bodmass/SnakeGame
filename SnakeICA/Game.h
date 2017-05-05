#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Collectable.h"
#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game(Snake& snake);
        void Run();
        virtual ~Game();
        bool isRunning = true;

    protected:

    private:
        void processEvents();
        void update();
        void render();
        void createUI();
        void updateUI(sf::Texture BGTexture, sf::Sprite BG, sf::Text TimerText, sf::Text TimerTitle, sf::Text AISText, sf::Text PlayerScore, sf::Text PlayerSText, sf::Text GlueText);
        sf::RenderWindow m_window;
        Snake & m_snake;
};

#endif // GAME_H
