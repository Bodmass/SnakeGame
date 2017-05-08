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

    std::cout << "Finished" << std::endl;
    return 0;
}
