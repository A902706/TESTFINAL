#include "Game.hpp"

void Game::create() {

	sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");//window

	Player player1;//player
	player1.setPosition(window.getSize().x / 2 - 100, window.getSize().y - 250);//position

	sf::Font font;//fonts
	font.loadFromFile("font.ttf");

	sf::Texture texture;//background texture	
	texture.loadFromFile("bg2.jpg");
	//git hub test
	sf::Texture alienSpriteTexture[10];//alien sprite texture array
	for (int i = 0; i < 10; ++i)
	{
		if (!alienSpriteTexture[i].loadFromFile("alien.png"))
		{
			std::cerr << "Sprite texture no work at index: " << i << std::endl;
		}
	}

	sf::Sprite sprite(texture);//set sprite to texture
	sprite.setPosition(0, 0);
	sprite.scale((window.getSize().x / sprite.getLocalBounds().width), (window.getSize().y / sprite.getLocalBounds().height));


	sf::Sprite shapeArray[10];//sprite array

	for (int i = 0; i < 10; i++) {//set shape size, color, position

		shapeArray[i].setTexture(alienSpriteTexture[i]);//set sprite texture
		shapeArray[i].setScale(0.3f, 0.3f);//set scale
		shapeArray[i].setPosition(-80, -80);//set pos
	}

	

	sf::Text gameOver("GAME OVER", font, 150);//game over stuff
	gameOver.setFillColor(sf::Color::Red);
	sf::FloatRect bounds2(gameOver.getLocalBounds());
	gameOver.setPosition(window.getSize().x / 2 - (bounds2.left + bounds2.width / 2), window.getSize().y / 2 - (bounds2.top + bounds2.height / 2));



	run(window, player1, font, shapeArray, gameOver, sprite);
}

void Game::run(sf::RenderWindow& window, Player& player, sf::Font& font, sf::Sprite shapeArray[], sf::Text gameOver, sf::Sprite sprite) {
	
	std::srand(static_cast<unsigned>(std::time(0)));
	float randomNum = 0;
	sf::Clock clock;
	int count = 0;

	while (window.isOpen())
	{

		std::string points = std::to_string(player.getPoints());
		sf::Text text("Points: " + points, font, 70);
		text.setFillColor(sf::Color::Red);
		sf::FloatRect bounds(text.getLocalBounds());
		text.setPosition(0, 0);

		float time = clock.restart().asSeconds();

		//window closing event
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}

		//character movement key presses
		if (event.type == sf::Event::EventType::KeyPressed) {
			if (event.key.code == sf::Keyboard::Left) {
				player.move(-1.0, 0);
			}
			if (event.key.code == sf::Keyboard::Right) {
				player.move(1.0, 0);
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = i; j < 10; j++) {
				for (int k = j; k < 10; k++)
					randomNum = std::rand() % 150;
				shapeArray[i].move(0, randomNum * time);

				if (shapeArray[i].getPosition().y > window.getSize().y) {
					randomNum = std::rand() % window.getSize().x;
					shapeArray[i].setPosition(randomNum, -20);
				}

			}
		}

		window.clear();

		//end of game code
		for (int i = 0; i < 10; i++) {
			if (player.getGlobalBounds().intersects(shapeArray[i].getGlobalBounds())) {
				window.draw(sprite);
				window.draw(gameOver);
				window.display();
				sf::sleep(sf::seconds(5));
				window.close();
			}
		}


		window.draw(sprite);
		window.draw(text);
		for (int i = 0; i < 10; ++i) {
			window.draw(shapeArray[i]);
		}
		window.draw(player);
		window.display();

	}
}

