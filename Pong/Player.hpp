#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SFML/Graphics.hpp"

class Player : public sf::Sprite {
private:
	sf::Texture texture;
	int points;

public:
	Player();

	void setPoints(const int newPoints);
	int getPoints() const;
};