#include "Game.hpp"
#include <vector>

void Game::create() {

	sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");//window

	Player player1;//player
	player1.setPosition(window.getSize().x / 2 - 100, window.getSize().y - 250);//position

	sf::Font font;//fonts
	font.loadFromFile("font.ttf");
	//Buttons
	//(TEXT, FONT, Size of background for words(DEFAULT TRANSPARENT use setFIllcolor() to change), location, visability status)
	MenuButton playButton("Play", font, sf::Vector2f(100, 75), sf::Vector2f(910, 510), true),
		instructionButton("Instructions", font, sf::Vector2f(200, 75), sf::Vector2f(850, 600), true),
		exitButton("Exit", font, sf::Vector2f(200, 75), sf::Vector2f(910, 700), true),
		backButton("Back", font, sf::Vector2f(200, 75), sf::Vector2f(0, 0), false);

	sf::Texture texture;//background texture	
	texture.loadFromFile("bg3.jpg");
	sf::Sprite sprite(texture);//set sprite to texture
	sprite.setPosition(0, 0);
	sprite.scale((window.getSize().x / sprite.getLocalBounds().width), (window.getSize().y / sprite.getLocalBounds().height));


	sf::Texture alienSpriteTexture;//alien sprite texture array
	alienSpriteTexture.loadFromFile("e1_SHIP.jpg");

	sf::Sprite shapeArray[10];//Sprite Array

	for (int i = 0; i < 10; i++) {//set shape size, color, position

		shapeArray[i].setTexture(alienSpriteTexture);//set sprite texture
		shapeArray[i].setScale(0.15f, 0.15f);//set scale(size)
		shapeArray[i].setPosition(-150, -150);//set pos
	}


	//text variables
	sf::Text gameOver("GAME OVER", font, 150),
		titleText("INVADERS", font, 150),
		instructionText("1. To shoot press up arrow \n2. To move: left and right arrows\n3. Survive as long as possible", font, 50);

	gameOver.setFillColor(sf::Color::Red); //text color
	titleText.setFillColor(sf::Color::Blue);
	instructionText.setFillColor(sf::Color::White);

	sf::FloatRect gameOverBounds(gameOver.getLocalBounds()),//text bounds
		titleBounds(titleText.getLocalBounds()),
	    instructionBounds(instructionText.getLocalBounds());
		
        gameOver.setPosition(window.getSize().x / 2 - (gameOverBounds.left + gameOverBounds.width / 2), window.getSize().y / 2 - (gameOverBounds.top + gameOverBounds.height / 2));//positions
	    titleText.setPosition((window.getSize().x - 1050) - (titleBounds.left + titleBounds.width / 2), (window.getSize().y - 750) - (titleBounds.top + titleBounds.height / 2));
	    instructionText.setPosition((window.getSize().x - 1050) - (titleBounds.left + titleBounds.width / 2), (window.getSize().y - 400) - (titleBounds.top + titleBounds.height / 2));

	menu(window, playButton, instructionButton,exitButton, backButton, sprite, titleText,
		 player1, font, shapeArray, gameOver, sprite, instructionText);

	//cc
}

void Game::menu(sf::RenderWindow& window, MenuButton& playButton, MenuButton& instructionButton, MenuButton& exitButton, MenuButton& backButton, sf::Sprite& background, sf::Text& title,//menu stuff
	            Player& player, sf::Font& font, sf::Sprite shapeArray[], sf::Text gameOver, sf::Sprite sprite, sf::Text instrunctionsText)//game stuff
{
	
	while (window.isOpen())
	{
		sf::Event buttonEvent;
		while (window.pollEvent(buttonEvent))
		{
			if (buttonEvent.type == sf::Event::Closed)
			{
				window.close();
			}
			if (buttonEvent.type == sf::Event::MouseButtonPressed)//PLAY BUTTON PRESSED
			{

				if (playButton.buttonCicked(sf::Mouse::getPosition(window)))
				{
					std::cout << "play button  CLICKED YAY" << std::endl;
					playButton.hideButton();//hide/show nessessary buttons
					instructionButton.hideButton();
					exitButton.hideButton();
					backButton.hideButton();

					window.clear();
					run(window, player, font, shapeArray, gameOver, sprite);
					return;
				}
			}
			if (buttonEvent.type == sf::Event::MouseButtonPressed)//INSTRUNCTION BUTTON
			{
				if (instructionButton.buttonCicked(sf::Mouse::getPosition(window)))
				{
					std::cout << "instruction button  CLICKED YAY" << std::endl;
					playButton.hideButton();//hide/show nessessary buttons
					instructionButton.hideButton();
					exitButton.hideButton();
					backButton.showButton();

				}
			}
			if (buttonEvent.type == sf::Event::MouseButtonPressed)//EXIT BUTTON PRESSED
			{
				if (exitButton.buttonCicked(sf::Mouse::getPosition(window)))
				{
					std::cout << " exit button  CLICKED YAY" << std::endl;
					window.close();
				}
			}
			if (buttonEvent.type == sf::Event::MouseButtonPressed)//BACK BUTTON PRESSED
			{
				if (backButton.buttonCicked(sf::Mouse::getPosition(window)))
				{
					std::cout << " exit button  CLICKED YAY" << std::endl;
					backButton.hideButton();//hide/show nessessary buttons
					playButton.showButton();
					instructionButton.showButton();
					exitButton.showButton();
				}
			}
		}
		window.clear();//clear prev content
		window.draw(background);
		window.draw(title);

		if (playButton.isButtonVisable() == true)
		{
			playButton.draw(window);
		}
		if (instructionButton.isButtonVisable() == true)
		{
			instructionButton.draw(window);
		}
		if (exitButton.isButtonVisable() == true)
		{
			exitButton.draw(window);
		}
		if (backButton.isButtonVisable() == true)
		{
			backButton.draw(window);
			window.draw(instrunctionsText);
		}

		window.display();//display stuff
	}
}

void Game::run(sf::RenderWindow& window, Player& player, sf::Font& font, sf::Sprite shapeArray[], sf::Text gameOver, sf::Sprite sprite) {

	std::srand(static_cast<unsigned>(std::time(0)));
	float randomNum = 0;
	sf::Clock clock;

	std::vector<sf::CircleShape> laser;

	while (window.isOpen())
	{
		float time = clock.restart().asSeconds();

		//window closing event
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}

		//player movement
		player.movePlayer(event);

		//laster shooting
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (laser.size() < 30) {//size of laser vector = thickness of bullet how far out it goes
				sf::CircleShape circle;
				circle.setRadius(window.getSize().x / 500);
				circle.setFillColor(sf::Color::Red);
				circle.setPosition(player.getPosition().x +10, player.getPosition().y - 10 );
				laser.push_back(circle);
			}
		}

		//move laser
		for (int i = 0; i < laser.size(); ++i) {
			laser[i].move(0, -1.5);  // Move laser upwards

			if (laser[i].getPosition().y < 0) {
				laser.pop_back();
			}
		}

		//code to detect is laser hits ship 
		for (int i = 0; i < laser.size(); ++i) {
			for (int j = 0; j < 10; j++) {
				if (laser[i].getGlobalBounds().intersects(shapeArray[j].getGlobalBounds())) {
						player.setPoints(player.getPoints() + 1);
						for (int i = 0; i < laser.size(); ++i) {
							laser[i].setFillColor(sf::Color::Transparent);
							laser.pop_back();
							player.textureLevelup();
							player.setScale(0.15f, 0.15f);
						}
						shapeArray[j].move(-300, -1000);
				}
			}
		}

		//allien movement
		for (int i = 0; i < 5; i++) {
			for (int j = i; j < 10; j++) {
				for (int k = j; k < 10; k++)
					randomNum = std::rand() % 120;
				shapeArray[i].move(0, randomNum * time);

				if (shapeArray[i].getPosition().y > window.getSize().y) {
					randomNum = std::rand() % window.getSize().x;
					shapeArray[i].setPosition(randomNum, -20);
				}

			}
		}


		//end of game code (player collison with alien)
		for (int i = 0; i < 10; i++) {
			if (player.getGlobalBounds().intersects(shapeArray[i].getGlobalBounds())) {
				window.draw(sprite);
				window.draw(gameOver);
				window.display();
				sf::sleep(sf::seconds(5));
				window.close();
			}
		}

		window.clear();
		window.draw(sprite);
		window.draw(player.displayPoints(font));

		for (int i = 0; i < 10; ++i) {
			window.draw(shapeArray[i]);
		}
		for (int i = 0; i < laser.size(); ++i) {
			window.draw(laser[i]);
		}

		window.draw(player);
		window.display();
	}
}
