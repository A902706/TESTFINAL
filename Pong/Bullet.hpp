#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SFML/Graphics.hpp"


class Bullet
{


public:



	Bullet(sf::Texture& bullet_textures, float x, float y, float bullet_speed) :mbulletspeed(bullet_speed)
	{
		mbulletsprite.setTexture(bullet_textures);
		mbulletsprite.setPosition(x,y);

	}


	void move(float time)
	{
		mbulletsprite.move(0, -mbulletspeed * time); //lets it move up 
	}

	sf::FloatRect Get_Bounds()const
	{
		return mbulletsprite.getGlobalBounds();

	}

	void draw_bullet(sf::RenderWindow& windows)
	{
		windows.draw(mbulletsprite);
	}


	bool offscreen_y_N(float Height_windows)const
	{
		return mbulletsprite.getPosition().y + mbulletsprite.getGlobalBounds().height < 0;
	}


private:

	sf::Sprite mbulletsprite; //sprite for the bullet
	float mbulletspeed; //speed of the bulelt


};


