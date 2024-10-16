#ifndef GAMEHANDLER_HPP
# define GAMEHANDLER_HPP

# include <iostream>
# include <vector>
# include <SFML/Graphics.hpp>

# include "Constants.hpp"
# include "Map.hpp"
# include "ScoreCounter.hpp"
# include "StartMenu.hpp"
# include "Snake.hpp"
# include "Tower.hpp"
# include "Arrow.hpp"


class GameHandler
{
	private:

	Map				map;
	Snake			snake;
	ScoreCounter	score;
	StartMenu		startmenu;
	TextBox			snakeStartInfo;

	sf::RenderWindow	*window;

	sf::Vector2f		snakeInfoPos;

	std::vector<Tower>	*towerVec; // I should probably have this vec only here, not in the map!
	std::vector<Arrow>	arrowVec;


	// 0 = start screen (NOT DONE), 1 = snake still, 2 = start, 3 = game over
	int		gameState;

	int		xDrawLimits[2]; // in pixels!
	int		yDrawLimits[2]; // in pixels!

	// Private functions

	void	setXLimits(sf::Vector2f snakePos);
	void	setYLimits(sf::Vector2f snakePos);


	public:

	// Should I have a default constructor here...?
	GameHandler(sf::RenderWindow *gameWindow);
	~GameHandler() {};

	void	initGame(std::string mapFile);
	void	updateGame();
	void	checkCollision();
	void	drawGame();

	void	displayStartMenu();
	void	startMenuInput(sf::Event &event);

	void	changeSnakeDir(sf::Event &event);


	int		getGameState();

	void	setGameState(int state);

};

#endif