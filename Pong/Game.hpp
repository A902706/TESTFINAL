#include "Player.hpp"
#include "Button.hpp"
class Game {

public:
	void run(sf::RenderWindow& window, Player& player, sf::Font& font, sf::Sprite shapeArray[], sf::Text gameOver, sf::Sprite sprite);
	void create();
	void menu(sf::RenderWindow& window, MenuButton& playButton, MenuButton& insructionButton, MenuButton& exitButton, MenuButton& backButton, sf::Sprite& background, sf::Text& title,//menu stuff
		      Player& player, sf::Font& font, sf::Sprite shapeArray[], sf::Text gameOver, sf::Sprite sprite, sf::Text instrunctions);//game stuff

};