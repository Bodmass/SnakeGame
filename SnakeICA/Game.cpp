#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Snake.h"
#include "Collectable.h"

Game::Game(Snake& snake) : m_window(sf::VideoMode(800, 600), "C++ Snake ICA : s6053935"), m_snake(snake)
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
    if (!font.loadFromFile("PopulationZeroBB.otf"))
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

    updateUI(BGTexture, BG, TimerText, TimerTitle, AISText, PlayerScore, PlayerSText, GlueText);

}

void Game::updateUI(sf::Texture BGTexture, sf::Sprite BG, sf::Text TimerText, sf::Text TimerTitle, sf::Text AISText, sf::Text PlayerScore, sf::Text PlayerSText, sf::Text GlueText)
{
    //m_window.draw(BG);
    m_window.draw(GlueText);
    m_window.draw(AISText);
    m_window.draw(PlayerSText);
    m_window.draw(PlayerScore);
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
                std::cout << "Direction set to Right" << std::endl;
                m_snake.setDirection(eDir::eWest);
                break;
            case sf::Keyboard::Left:
                std::cout << "Direction set to Left" << std::endl;
                m_snake.setDirection(eDir::eEast);
                break;
            case sf::Keyboard::Up:
                std::cout << "Direction set to Up" << std::endl;
                m_snake.setDirection(eDir::eNorth);
                break;
            case sf::Keyboard::Down:
                std::cout << "Direction set to Down" << std::endl;
                m_snake.setDirection(eDir::eSouth); //= eDir::eSouth;
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
    for(sf::RectangleShape& Shape:Walls)
    {
        m_window.draw(Shape);

    }
    m_snake.Render(m_window);
    //Fruit.Render(m_window);
    m_window.display();
}

void Game::update()
{

    m_snake.Update();
    CheckCollisions(&m_snake);

}

bool Game::CheckCollisions(Snake* snake)
{
    for(sf::RectangleShape& Shape:Walls)
    {
        if(snake->getHead()->getGlobalBounds().intersects(Shape.getGlobalBounds()))
        {
            snake->hasDied();
            return true;
        }
    }
    return false;
}

void Game::Run()
{
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

    while(m_window.isOpen())
    {
        update();
        render();
        processEvents();
    }
}
