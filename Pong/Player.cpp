#include "Player.hpp"

Player::Player() {
	points = 0;

	texture.loadFromFile("spaceship.png");
	setTexture(texture);
	scale(0.1, 0.1);
}

void Player::setPoints(const int newPoints) {
	points = newPoints;
}
int Player::getPoints() const {
	return points;
}