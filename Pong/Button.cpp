#include "Button.hpp"

MenuButton::MenuButton(const std::string& newText, const sf::Font newFont, sf::Vector2f& newSize, sf::Vector2f& newPos, bool newButtonStatus)
{
	{
		//button dimensions
		mButton.setSize(newSize);//make button Size
		mButton.setPosition(newPos);//set position
		mButton.setFillColor(sf::Color::Transparent);// set color

		//button font, \text
		mFont = newFont;
		mText.setFont(mFont); //set font
		mText.setString(newText);// set terxt inside in font
		mText.setCharacterSize(50);//50 testing size
		mText.setFillColor(sf::Color::White);//set text color

		sf::FloatRect textPosition = mButton.getLocalBounds();

		//set text position used reference from sfml website on how to go about
		mText.setPosition(newPos.x + (newSize.x - textPosition.width) / 2.0f - textPosition.left, newPos.y + (newSize.y - textPosition.height) / 2.0f - textPosition.top);

		//button status
		mButtonVisable = newButtonStatus;
	}
}

void MenuButton::draw(sf::RenderWindow& window)
{
	if (mButtonVisable)
	{
		window.draw(mButton);
		window.draw(mText);
	}
}

void MenuButton::setFillColor(const sf::Color& hoverColor)
{
	if (mButtonVisable)
	{
		mButton.setFillColor(hoverColor);
	}
}

bool MenuButton::buttonCicked(sf::Vector2i& mousePosition)
{
	if (mButtonVisable)
	{
		return mButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
	}

	return false;
}

void MenuButton::hideButton()
{
	mButtonVisable = false;
}

void MenuButton::showButton()
{
	mButtonVisable = true;
}

bool MenuButton::isButtonVisable()
{
	if (mButtonVisable == true)
	{
		return true;//if true return it
	}

	return false;// return default (false)
}
