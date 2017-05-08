#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Collectable.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>

template<typename T>
std::string toString(T val)
{
    std::stringstream ss;
    ss << val;
    return ss.str();
}

class Game
{
public:
    ///Set's up the Snake Game
    Game();
    ///Run the game
    void Run();
    void Restart();
    void CheckEnd();
    virtual ~Game();
    ///Check if the game is still running
    bool isRunning = true;

protected:

private:
    ///Vector used for walls
    std::vector<sf::RectangleShape> Walls;
    ///Vector used for collectables
    std::vector<Collectable*> Collectables;
    void processEvents();
    ///Update the game every frame
    void update();
    ///Render to the window
    void render();
    ///Create the game's UI (Score, Timer, Glue)
    void createUI();
    ///Update the game's UI
    void updateUI(sf::Text WinnerDraw, sf::Text Winner1Text, sf::Text Winner2Text, sf::Text TimerText, sf::Text TimerTitle, sf::Text PlayerS2Text, sf::Text PlayerScore, sf::Text PlayerSText, sf::Text GlueText, sf::Text PlayerGlueText, sf::Text Player2Score, sf::Text Player2GlueTitle, sf::Text Player2GlueText);
    ///Create the window to render to
    sf::RenderWindow m_window;
    ///Check the Collisions with the Snake and walls.
    bool CheckCollisions(Snake* snake);
    ///Timer Clock for the Main Game
    sf::Clock MainClock;
    ///Clock to remember the Timer when its gameover
    int HoldClock = 0;
    ///Textures Vector for the Collectable
    std::vector<sf::Texture> Textures;
    ///Vector to Create the player snakes
    std::vector<Snake> m_Snakes;
    ///Boolean to set gameover
    bool gameover = false;

};

#endif // GAME_H
