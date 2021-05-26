#include <SFML/Graphics.hpp>
#include <ctime>
#include <windows.h>
#include <iostream>
#include <math.h>
#include "Header.h"

using namespace sf;

int main()
{
	srand(time(0));
	Triangle* triangle = new Triangle[1]
	{
		{0, 0, 0, 20, 20, 10, 20, 20}
	};

	Square* square = new Square[1]
	{
		{0, 0, 0, 20, 20, 20, 300, 400, 20, 0}
	};

	Pentagon* pentagon = new Pentagon[1]
	{
		{0, 0, 12, 15, 27, 15, 400, 400, 39, 0, 20, -15}
	};
	RenderWindow window(VideoMode(1300, 700), "LUDOJOP!");
	menu(window);
	Clock clock;
	//std::cout << triangle.gettercenterx() << " " << triangle.gettercentery() << std::endl;
	//std::cout << square.gettercenterx() << " " << square.gettercentery() << std::endl;
	
	Texture Background;
	Background.loadFromFile("Images/fonforgame.png");

	Sprite iBackground;
	iBackground.setTexture(Background);


	Texture Portal[3];
	Portal[0].loadFromFile("Images/birthportal1.png");
	Portal[1].loadFromFile("Images/birthportal2.png");
	Portal[2].loadFromFile("Images/birthportal3.png");

	Texture Heart;
	Heart.loadFromFile("Images/Heart.png");


	Texture Cloud[3];
	Cloud[0].loadFromFile("Images/cloud.png");
	Cloud[1].loadFromFile("Images/cloud1.png");
	Cloud[2].loadFromFile("Images/cloud2.png");

	Texture HP1;
	HP1.loadFromFile("Images/HP1.png");

	Texture HP2;
	HP2.loadFromFile("Images/HP2.png");

	Texture HP3;
	HP3.loadFromFile("Images/HP3.png");



	Sprite iHP[3];
	iHP[0].setTexture(HP1);
	iHP[1].setTexture(HP2);
	iHP[2].setTexture(HP3);

	int iforportal = 0;
	int cloudcounter = 0;
	int portalcounter = 0;



	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		Sprite iPortal[3];
		if (portalcounter == 50)
		{
			portalcounter = 0;
			iforportal++;
		}
		portalcounter++;
		if (iforportal == 3)
		{
			iforportal = 0;
		}

		iPortal[iforportal].setTexture(Portal[iforportal]);
		iPortal[iforportal].setPosition(570, -22);


		window.draw(iPortal[iforportal]);
		draw(window, triangle, square, pentagon, iHP);
		Objects(window, triangle, square, pentagon, Cloud, Heart);
		delay--;

		window.display();
		window.draw(iBackground);
	}
	return 0;
}