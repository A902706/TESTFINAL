#include "SFML/Graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


class MenuButton 
{
public:
	//constructor
	MenuButton(const std::string& newText, const sf::Font newFont, sf::Vector2f& newSize, sf::Vector2f& newPos, bool newButtonStatus);

	void draw(sf::RenderWindow& window);

	void setFillColor(const sf::Color& hoverColor);

	bool buttonCicked(sf::Vector2i& mousePosition); 

	void hideButton();

	void showButton();

	bool isButtonVisable();

private:
	sf::RectangleShape mButton; //button variabvles
	sf::Text  mText;//text variables
	sf::Font  mFont;//font variable
	bool mButtonVisable;//makes buttopn visable/invisable
};