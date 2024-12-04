#include "Player.hpp"

class Game {

public:
	void run(sf::RenderWindow& window, Player& player, sf::Font &font, sf::Sprite shapeArray[], sf::Text gameOver, sf::Sprite sprite);
	void create();

};