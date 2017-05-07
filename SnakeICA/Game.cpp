#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Snake.h"
#include "Collectable.h"

Game::Game() : m_window(sf::VideoMode(800, 600), "C++ Snake ICA : s6053935")
{
    //createUI();
    //ctor
}

Game::~Game()
{
    //dtor
}


void Game::createUI()
{
    //std::cout<<"Constructing UI"<<std::endl;
    sf::Texture BGTexture;
    if (!BGTexture.loadFromFile("Textures/Arena.png"))
    {

    }
    sf::Sprite BG(BGTexture);
    sf::Font font;
    if (!font.loadFromFile("pxl.ttf"))
    {

    }
    //return EXIT_FAILURE;
    //Glue Title

    sf::Text GlueText("GLUE", font, 35);
    GlueText.setColor(sf::Color::White);
    GlueText.setPosition(50, 535);

    //Player Score
    sf::Text PlayerSText("Player Score", font, 35);
    PlayerSText.setColor(sf::Color::White);
    PlayerSText.setPosition(50, 460);

    sf::Text PlayerScore(m_snake.getScore(), font, 35);
    PlayerScore.setColor(sf::Color::White);
    PlayerScore.setPosition(115, 490);

    sf::Text PlayerGlueText(m_snake.getGlue(), font, 35);
    PlayerGlueText.setColor(sf::Color::White);
    PlayerGlueText.setPosition(115, 535);


    //AI Score
    sf::Text AISText("AI Score", font, 35);
    AISText.setColor(sf::Color::White);
    AISText.setPosition(650, 460);

    //Timer
    sf::Text TimerTitle("TIME", font, 45);
    TimerTitle.setColor(sf::Color::White);
    TimerTitle.setPosition(380, 475);

    int count = 1;

    //std::string timeshow = std::to_string(90);

    sf::Text TimerText("90", font, 45); //reduce to 0
    TimerText.setColor(sf::Color::White);
    TimerText.setPosition(390, 525);

    updateUI(BGTexture, BG, TimerText, TimerTitle, AISText, PlayerScore, PlayerSText, GlueText, PlayerGlueText);

}

void Game::updateUI(sf::Texture BGTexture, sf::Sprite BG, sf::Text TimerText, sf::Text TimerTitle, sf::Text AISText, sf::Text PlayerScore, sf::Text PlayerSText, sf::Text GlueText, sf::Text PlayerGlueText)
{

    //Makes the Main Clock of the game count down
    //I will be Making the Clock count up and Minus is by 90 to make it seem like the clock is counting down
    if(MainClock.getElapsedTime().asSeconds() >= 90) //If the Main Clock has already gone over 90 seconds, force the display to 0.
    {
        TimerText.setString("0");
    }
    else
        TimerText.setString(toString(90-(int)(MainClock.getElapsedTime().asSeconds()))); //Setting the Timer to 90 - the Main Clock

    //Drawing all the UI to the screen
    m_window.draw(GlueText);
    m_window.draw(AISText);
    m_window.draw(PlayerSText);
    m_window.draw(PlayerScore);
    m_window.draw(PlayerGlueText);
    m_window.draw(TimerTitle);
    m_window.draw(TimerText);
}


void Game::processEvents()
{
    sf::Event event; //put this in player inheriteance snake thingy
    while (m_window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::KeyPressed:
            //std::cout<<"checking what key was pressed";
            switch(event.key.code)
            {
            case sf::Keyboard::Right:
                //std::cout << "Direction set to Right" << std::endl;
                m_snake.setDirection(eDir::eWest);
                break;
            case sf::Keyboard::Left:
                //std::cout << "Direction set to Left" << std::endl;
                m_snake.setDirection(eDir::eEast);
                break;
            case sf::Keyboard::Up:
                //std::cout << "Direction set to Up" << std::endl;
                m_snake.setDirection(eDir::eNorth);
                break;
            case sf::Keyboard::Down:
                //std::cout << "Direction set to Down" << std::endl;
                m_snake.setDirection(eDir::eSouth); //= eDir::eSouth;
                break;
            case sf::Keyboard::Space:
                m_snake.useGlue();
                break;
            default:
                break;
            }
        default:
            break;
        }

    }
}

void Game::render()
{
    m_window.clear();

    createUI();

    for(sf::RectangleShape& Shape:Walls) //Loop through all the Walls and draws them
    {
        m_window.draw(Shape);

    }
    for(Collectable* Shape:Collectables) //Loop through all the Collectables and draws them
    {
        m_window.draw(*Shape->getCollectable());

    }
    m_snake.Render(m_window);
    //Fruit.Render(m_window);
    m_window.display();
}

void Game::update()
{
    sf::sleep(sf::Time(sf::milliseconds(10)));
    m_snake.Update();
    CheckCollisions(&m_snake); //Check the Collision with the Walls & Collectables
    for(int i = 0; i<Collectables.size(); i++) //Checks through all the current Collectables in the vector and checks if they've eaten, if they have been, remove it from the vector list.
    {
        Collectables[i]->Update();
        if(Collectables[i]->isEaten())
        {
            //Collectables.erase(Collectables.begin() + i);
            Collectables[i]->CollectableInactive();

        }
    }

    for(Collectable* Shape:Collectables)
    {
        for(Collectable* Shape2:Collectables)
        {
            if(Shape==Shape2)
                break;
            if(Shape->getCollectable()->getGlobalBounds().intersects(Shape2->getCollectable()->getGlobalBounds())) //If the Snake Head has intersected the bounds of any of the collectables, eat it and add the score.
            {
                if(Shape->CheckActive())
                {
                    Shape->CollectableMove(Shape->RandPos());
                }
            }
        }
    }

}

bool Game::CheckCollisions(Snake* snake)
{
    for(sf::RectangleShape& Shape:Walls) //Loop through the walls
    {
        if(snake->getHead()->getGlobalBounds().intersects(Shape.getGlobalBounds())) //If the Snake Head has intersected the bounds of any of the walls, kill the snake.
        {
            snake->hasDied();
            return true;
        }
    }
    for(Collectable* Shape:Collectables)
    {
        if(snake->getHead()->getGlobalBounds().intersects(Shape->getCollectable()->getGlobalBounds())) //If the Snake Head has intersected the bounds of any of the collectables, eat it and add the score.
        {
            snake->addScore(Shape->addScore());
            snake->addSegment(Shape->Eat());
            //snake->eatGlue(Shape.addGlue());
            if(dynamic_cast<Glue*>(Shape)) {snake->eatGlue(dynamic_cast<Glue*>(Shape)->addGlue());}
            return true;
        }
    }
    return false;
}

void Game::Run()
{
    //Setting up Vectors for the Textures, Walls and Collectables.
    Textures.push_back(sf::Texture());
    Textures.back().loadFromFile("Textures/Apple.png"); //Textures[0]
    Textures.push_back(sf::Texture());
    Textures.back().loadFromFile("Textures/Pear.png"); //Textures[1]
    Textures.push_back(sf::Texture());
    Textures.back().loadFromFile("Textures/Banana.png"); //Textures[2]
    Textures.push_back(sf::Texture());
    Textures.back().loadFromFile("Textures/Strawberry.png"); //Textures[3]
    Textures.push_back(sf::Texture());
    Textures.back().loadFromFile("Textures/Kiwi.png"); //Textures[4]
    Textures.push_back(sf::Texture());
    Textures.back().loadFromFile("Textures/Glue.png"); //Textures[5]
    Textures.push_back(sf::Texture());
    Textures.back().loadFromFile("Textures/PlayerSnake.png"); //Textures[6]
    Walls.push_back(sf::RectangleShape(sf::Vector2f(800,20))); //Top
    Walls.back().setPosition(sf::Vector2f(0,0));
    Walls.push_back(sf::RectangleShape(sf::Vector2f(800,20))); //Bottom
    Walls.back().setPosition(sf::Vector2f(0,580));
    Walls.push_back(sf::RectangleShape(sf::Vector2f(800,20))); //Bottom
    Walls.back().setPosition(sf::Vector2f(0,440));
    Walls.push_back(sf::RectangleShape(sf::Vector2f(20,600))); //Left
    Walls.back().setPosition(sf::Vector2f(0,0));
    Walls.push_back(sf::RectangleShape(sf::Vector2f(20,600))); //Right
    Walls.back().setPosition(sf::Vector2f(780,0));
    Collectables.push_back(new Collectable("Apple", 5, 1, Textures[0], 5)); //Pushes back the collectable with the Collectable Name, Score to Add, Segment Amount and the Texture to load.
    Collectables.push_back(new Collectable("Pear", 10, 2, Textures[1], 10));
    Collectables.push_back(new Collectable("Banana", 20, 3, Textures[2], 15));
    Collectables.push_back(new Collectable("Strawberry", 40, 4, Textures[3], 20));
    Collectables.push_back(new Collectable("Kiwi", 80, 5, Textures[4], 25));
    Collectables.push_back(new Glue("Glue", 0, 0, Textures[5], 2));
    m_snake = Snake("Snakeman", Textures[6]);



    while(m_window.isOpen())
    {
        update();
        render();
        processEvents();
    }
}
