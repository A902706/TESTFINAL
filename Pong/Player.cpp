#include "Player.hpp"

Player::Player() {
	points = 0;

	texture.loadFromFile("level1Ship.png"); //load player image
	setTexture(texture);//sset (texture)
	scale(0.9, 0.9);//set scale(size)
}

void Player::setPoints(const int newPoints) {
	points = newPoints;
}
int Player::getPoints() const {
	return points;
}

sf::Text Player::displayPoints(sf::Font& font) {
	std::string points = std::to_string(getPoints());
	sf::Text text("Points: " + points, font, 70);
	text.setFillColor(sf::Color::Red);
	sf::FloatRect bounds(text.getLocalBounds());
	text.setPosition(0, 0);
	return text;
}

void  Player::movePlayer(sf::Event event) {

	if (event.type == sf::Event::EventType::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left) {
			move(-0.55, 0);


		}
		if (event.key.code == sf::Keyboard::Right) {
			move(0.5, 0);

		}
	}
}

void Player::textureLevelup()
{
	if (points == 10)
	{
		texture.loadFromFile("level2Ship.png");
	}
	else if (points == 20)
	{
		texture.loadFromFile("level3Ship.png");

	}
	else if (points == 30)
	{
		texture.loadFromFile("level4Ship.png");

	}
}
