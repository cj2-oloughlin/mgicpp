
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	// init sprites
	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png"))
	{
		std::cout << "background texture did not load\n";
	}
	background.setTexture(background_texture);

	if (!bird_texture.loadFromFile("../Data/Images/kenney_physicspack/PNG/Aliens/alienGreen_round.png"))
	{
		std::cout << "bird texture did not load\n";
	}
	bird.setTexture(bird_texture);
	bird.setPosition(100, 100);


	// init text
	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font did not load \n";
	}

	title_text.setString("Whack-a-Mole: The Squeakuel");
	title_text.setFont(font);
	title_text.setCharacterSize(200);
	title_text.setFillColor(sf::Color(255,255.255,128));

	title_text.setPosition(
		window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
		window.getSize().y / 2 - title_text.getGlobalBounds().height / 2);

  return true;
}

void Game::update(float dt)
{
	// exit state
	if (gameStates == GameStates::EXIT)
	{
		window.close();
	}
}

void Game::render()
{
	window.draw(background);
	window.draw(bird);
	window.draw(title_text);
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
	// quitting with the esc key
	if (event.key.code == sf::Keyboard::Escape)
	{
		gameStates = GameStates::EXIT;
	}
}


