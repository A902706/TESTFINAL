#include "Player.hpp"

Player::Player() {
	points = 0;

	texture.loadFromFile("lvl1_SHIP.jpg");
	setTexture(texture);
	scale(0.15, 0.15);
}

void Player::setPoints(const int newPoints) {
	points = newPoints;
}
int Player::getPoints() const {
	return points;
}