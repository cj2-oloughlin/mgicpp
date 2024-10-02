
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Font font;

  sf::Text title_text;

  sf::Sprite bird;
  sf::Texture bird_texture;

  sf::Sprite background;
  sf::Texture background_texture;


  //Gamestates
  enum class GameStates {MENU, GAMEPLAY, EXIT, LOSE};
  GameStates gameStates = GameStates::MENU;
};

#endif // PLATFORMER_GAME_H
