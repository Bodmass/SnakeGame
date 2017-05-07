/*
  Snake ICA start project using SFML
    SFML documentation: http://www.sfml-dev.org/documentation/2.4.2/classes.php
  Windows build
    To build on Windows you need to have the correct version of CodeBlocks
      Download from here: http://www.codeblocks.org/downloads/26
      Must be the download titled "codeblocks-16.01mingw-setup.exe"
*/

#include <iostream>
#include <cstdlib>
// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Collectable.h"
#include "Game.h"

int main()
{
    srand (time(NULL));

    //sf::Clock clock;

    Game game;
    std::cout << "Starting" << std::endl;
    game.Run();

    /* Git commands
    git status
    git add .
    git commit -m "Changes"
    git push
    //Other git commands
    git config --global --edit
    git commit --ammend --reset-author

    */
    // All SFML types and functions are contained in the sf namespace

    // Create an instance of the SFML RenderWindow type which represents the display
    // and initialise its size and title text
    //sf::RenderWindow window(sf::VideoMode(800, 600), "C++ Snake ICA : s6053935");
    // We can still output to the console window


    // Main loop that continues until we call Close()

    /*
            if (PlayerSnake.getPos().x<48){
                PlayerSnake.hasDied();
                }
            if (PlayerSnake.getPos().y<32){
                PlayerSnake.hasDied();
                }
            if (PlayerSnake.getPos().y>window.getSize().y - 148){
                PlayerSnake.hasDied();
                }
            if (PlayerSnake.getPos().x>window.getSize().x - 64){
                PlayerSnake.hasDied();
                }
    */
    /*

            PlayerSnake.Update();

            // We must clear the window each time round the loop

            window.clear();
            window.draw(BG);
            window.draw(GlueText);
            window.draw(PlayerS2Text);
            window.draw(PlayerSText);
            window.draw(PlayerScore);
            window.draw(TimerTitle);
            window.draw(TimerText);
            PlayerSnake.Render(window);
            Fruit.Render(window);
            // draw our circle shape to the window

            // Get the window to display its contents
            window.display();
            */
    //}

    std::cout << "Finished" << std::endl;
    return 0;
}
