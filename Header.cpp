#include "Header.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <windows.h>
#include <iostream>
#include <math.h>

using namespace sf;


int masbottom[3] = { 2, 3, 4 };
int masright[3] = { 1, 3, 5 };
int masleft[3] = { 0, 2, 6 };
int masup[3] = { 0, 1, 7 };
int counter = rand() % 1000;
int icounter = 0;

int counterofall = 2;

int countertriangle = 1;
int countersquare = 1;
int counterpentagon = 0;
const int radius = 35;
int delay = 0;

using namespace sf;

	Point::Point(int x1, int y1) :x1(x1), y1(y1){};
	Point::Point() {};



	Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int movex, int movey) : Point(x1, y1), x2(x2), x3(x3), y2(y2), y3(y3), movex(movex), movey(movey) {
		centerx = (x3 - (y2 / 2)) / 2;
		centery = y2 / 2;
		hp = 0;
		for (int i = 0; i < 3; ++i) {
			color[i] = rand() % 255 + 1;
		}
		temp = 7;
	};

	Triangle::Triangle(const Triangle& triangle) {
		this->x1 = triangle.x1;
		this->y1 = triangle.y1;
		this->x2 = triangle.x2;
		this->x3 = triangle.x3;
		this->y2 = triangle.y2;
		this->y3 = triangle.y3;
		this->centerx = triangle.centerx;
		this->centery = triangle.centery;
		this->hp = 0;
		this->color[0] = triangle.color[0];
		this->color[1] = triangle.color[1];
		this->color[2] = triangle.color[2];
		this->movex = 600;
		this->movey = 20;
		this->temp = 4;
	};

	Triangle::Triangle() {}

	Triangle* Triangle::increasemas(Triangle mas[], int countertriangle, int exsisti)
	{
		Triangle newelement(mas[exsisti]);
		Triangle* newmas = new Triangle[countertriangle];
		newmas[countertriangle - 1] = newelement;
		for (int i = 0; i < countertriangle - 1; ++i)
		{
			newmas[i] = mas[i];
		}
		delete[] mas;
		return newmas;
	}

	Triangle* Triangle::delmas(Triangle mas[], int& countertriangle)
	{
		bool dead = false;
		for (int i = 0; i < countertriangle; ++i)
		{
			if (mas[i].hp == 3)
			{
				dead = true;
			}
		}
		if (dead == true)
		{
			countertriangle--;
			counterofall--;
			Triangle* newmas = new Triangle[countertriangle];
			for (int i = 0, k = 0; i < countertriangle + 1; ++i)
			{
				if (mas[i].hp != 3)
				{
					newmas[k] = mas[i];
					k++;
				}
			}
			delete[] mas;
			return newmas;
		}
	}

	int Triangle::checkforexistence(Triangle mas[], int countertriangle)
	{
		for (int i = 0; i < countertriangle; ++i)
		{
			if (mas[i].hp != 3)
				return i;
			else
				return 0;
		}
	}

	int Triangle::getterx1() {
		return x1;
	}
	int Triangle::getterx2() {
		return x2;
	}
	int Triangle::getterx3() {
		return x3;
	}
	int Triangle::gettery1() {
		return y1;
	}
	int Triangle::gettery2() {
		return y2;
	}
	int Triangle::gettery3() {
		return y3;
	}
	int Triangle::gettermovex() {
		return movex;
	}
	int Triangle::gettermovey() {
		return movey;
	}
	int Triangle::gettercolorR() {
		return color[0];
	}
	int Triangle::gettercolorG() {
		return color[1];
	}
	int Triangle::gettercolorB() {
		return color[2];
	}
	int Triangle::gettercenterx() {
		return centerx;
	}
	int Triangle::gettercentery() {
		return centery;
	}
	int Triangle::getterhp() {
		return hp;
	}

	void Triangle::setterhp(int hp) {
		this->hp = hp;
	}

	void Triangle::border() {
		if (movey == 670)
		{
			temp = masbottom[rand() % 3];
		}
		if (movex == 1280)
		{
			temp = masright[rand() % 3];
		}
		if (movex == 10)
		{
			temp = masleft[rand() % 3];
		}
		if (movey == 10)
		{
			temp = masup[rand() % 3];
		}
		if (icounter == counter)
		{
			temp = rand() % 8;
			counter = rand() % 1000;
			icounter = 0;
		}
		++icounter;

	}


	void Triangle::move() {
		//	temp = rand() % 6;
		if (temp == 0)
		{
			movex += 1;
			movey += 1;
		}
		if (temp == 1)
		{
			movex -= 1;
			movey += 1;
		}
		if (temp == 2)
		{
			movex += 1;
			movey -= 1;
		}
		if (temp == 3)
		{
			movex -= 1;
			movey -= 1;
		}
		if (temp == 4)
		{
			movex -= 0;
			movey -= 1;
		}
		if (temp == 5)
		{
			movex -= 1;
			movey -= 0;
		}
		if (temp == 6)
		{
			movex += 1;
			movey -= 0;
		}
		if (temp == 7)
		{
			movex -= 0;
			movey += 1;
		}
	}




	Square::Square(int x1, int y1, int x2, int y2, int x3, int y3, int movex, int movey, int x4, int y4) :Triangle(x1, y1, x2, y2, x3, y3, movex, movey) {
		centerx = x3 / 2;
		centery = y2 / 2;
		hp = 0;
		for (int i = 0; i < 3; ++i) {
			color[i] = rand() % 255 + 1;
		}
		this->x4 = x4;
		this->y4 = y4;
	}

	Square::Square() {};

	Square::Square(const Square& square) {
		this->x1 = square.x1;
		this->y1 = square.y1;
		this->x2 = square.x2;
		this->x3 = square.x3;
		this->x4 = square.x4;
		this->y2 = square.y2;
		this->y3 = square.y3;
		this->y4 = square.y4;
		this->centerx = square.centerx;
		this->centery = square.centery;
		this->hp = 0;
		this->color[0] = square.color[0];
		this->color[1] = square.color[1];
		this->color[2] = square.color[2];
		this->movex = 600;
		this->movey = 20;
		this->temp = 4;
	};

	Square* Square::increasemas(Square mas[], int countertsquare, int exsisti)
	{
		Square newelement(mas[exsisti]);
		Square* newmas = new Square[countertsquare];
		newmas[countertsquare - 1] = newelement;
		for (int i = 0; i < countertsquare - 1; ++i)
		{
			newmas[i] = mas[i];
		}
		delete[] mas;
		return newmas;
	}

	Square* Square::delmas(Square mas[], int& countertsquare)
	{
		bool dead = false;
		for (int i = 0; i < countertsquare; ++i)
		{
			if (mas[i].hp == 3)
			{
				dead = true;
			}
		}
		if (dead == true)
		{
			countertsquare--;
			counterofall--;
			Square* newmas = new Square[countertsquare];
			for (int i = 0, k = 0; i < countertsquare + 1; ++i)
			{
				if (mas[i].hp != 3)
				{
					newmas[k] = mas[i];
					k++;
				}
			}
			delete[] mas;
			return newmas;
		}
	}

	int Square::checkforexistence(Square mas[], int countertsquare)
	{
		for (int i = 0; i < countertsquare; ++i)
		{
			if (mas[i].hp != 3)
				return i;
			else
				return 0;
		}
	}

	int Square::getterx4() {
		return x4;
	}
	int Square::gettery4() {
		return y4;
	}


	Pentagon::Pentagon(int x1, int y1, int x2, int y2, int x3, int y3, int movex, int movey, int x4, int y4, int x5, int y5) : Square(x1, y1, x2, y2, x3, y3, movex, movey, x4, y4) {
		centerx = x4 / 2;
		centery = y1;
		hp = 0;
		for (int i = 0; i < 3; ++i) {
			color[i] = rand() % 255 + 1;
		}
		this->x5 = x5;
		this->y5 = y5;
	}
	Pentagon::Pentagon() {}

	int Pentagon::getterx5() {
		return x5;
	}
	int Pentagon::gettery5() {
		return y5;
	}

	Pentagon* Pentagon::increasemas(Pentagon mas[], int countertpentagon, int exsisti)
	{
		Pentagon newelement(mas[exsisti]);
		Pentagon* newmas = new Pentagon[countertpentagon];
		newmas[countertpentagon - 1] = newelement;
		for (int i = 0; i < countertpentagon - 1; ++i)
		{
			newmas[i] = mas[i];
		}
		delete[] mas;
		return newmas;
	}

	int Pentagon::checkforexistence(Pentagon mas[], int counterpentagon)
	{
		for (int i = 0; i < counterpentagon; ++i)
		{
			if (mas[i].hp != 3)
				return i;
			else
				return 0;
		}
	}

	Pentagon* Pentagon::delmas(Pentagon mas[], int& countertpentagon)
	{
		bool dead = false;
		for (int i = 0; i < countertpentagon; ++i)
		{
			if (mas[i].hp == 3)
			{
				dead = true;
			}
		}
		if (dead == true)
		{
			countertpentagon--;
			counterofall--;
			Pentagon* newmas = new Pentagon[countertpentagon];
			for (int i = 0, k = 0; i < countertpentagon + 1; ++i)
			{
				if (mas[i].hp != 3)
				{
					newmas[k] = mas[i];
					k++;
				}
			}
			delete[] mas;
			return newmas;
		}
	}

	void draw(RenderWindow& window, Triangle*& triangle, Square*& square, Pentagon*& pentagon, Sprite iHP[]) {
		CircleShape circle[30];
		for (int i = 0; i < 30; ++i) {
			circle[i].setRadius(radius);
		}


		for (int i = 0; i < countertriangle; ++i) {

			circle[i].setOrigin(radius, radius);
			circle[i].setFillColor(Color(20, 60, 40, 240));
			circle[i].move(triangle[i].gettercenterx() + triangle[i].gettermovex(), triangle[i].gettercentery() + triangle[i].gettermovey());
			window.draw(circle[i]);

			ConvexShape triangle1;

			triangle1.setFillColor(Color(triangle[i].gettercolorR(), triangle[i].gettercolorG(), triangle[i].gettercolorB()));

			triangle1.setPointCount(3);
			triangle1.setPoint(0, Vector2f(triangle[i].getterx1(), triangle[i].gettery1()));
			triangle1.setPoint(1, Vector2f(triangle[i].getterx2(), triangle[i].gettery2()));
			triangle1.setPoint(2, Vector2f(triangle[i].getterx3(), triangle[i].gettery3()));
			triangle[i].border();
			triangle[i].move();
			triangle1.move(triangle[i].gettermovex(), triangle[i].gettermovey());
			iHP[triangle[i].getterhp()].setPosition(triangle[i].gettermovex() - 14, triangle[i].gettermovey() - 32);

			window.draw(iHP[triangle[i].getterhp()]);
			window.draw(triangle1);


		}

		for (int i = 0, j = 10; i < countersquare; ++i, ++j) {

			circle[j].setOrigin(radius, radius);
			circle[j].setFillColor(Color(20, 60, 40, 240));
			circle[j].move(square[i].gettercenterx() + square[i].gettermovex(), square[i].gettercentery() + square[i].gettermovey());
			window.draw(circle[j]);

			ConvexShape square1;

			square1.setFillColor(Color(square[i].gettercolorR(), square[i].gettercolorG(), square[i].gettercolorB()));

			square1.setPointCount(4);
			square1.setPoint(0, Vector2f(square[i].getterx1(), square[i].gettery1()));
			square1.setPoint(1, Vector2f(square[i].getterx2(), square[i].gettery2()));
			square1.setPoint(2, Vector2f(square[i].getterx3(), square[i].gettery3()));
			square1.setPoint(3, Vector2f(square[i].getterx4(), square[i].gettery4()));
			square[i].border();
			square[i].move();
			square1.move(square[i].gettermovex(), square[i].gettermovey());
			iHP[square[i].getterhp()].setPosition(square[i].gettermovex() - 14, square[i].gettermovey() - 32);

			window.draw(iHP[square[i].getterhp()]);
			window.draw(square1);



		}


		for (int i = 0, j = 20; i < counterpentagon; ++i, ++j) {

			circle[j].setOrigin(radius, radius);

			circle[j].setFillColor(Color(20, 60, 40, 240));
			circle[j].move(pentagon[i].gettercenterx() + pentagon[i].gettermovex(), pentagon[i].gettercentery() + pentagon[i].gettermovey());
			window.draw(circle[j]);

			ConvexShape pentagon1;

			pentagon1.setFillColor(Color(pentagon[i].gettercolorR(), pentagon[i].gettercolorG(), pentagon[i].gettercolorB()));

			pentagon1.setPointCount(5);
			pentagon1.setPoint(0, Vector2f(pentagon[i].getterx1(), pentagon[i].gettery1()));
			pentagon1.setPoint(1, Vector2f(pentagon[i].getterx2(), pentagon[i].gettery2()));
			pentagon1.setPoint(2, Vector2f(pentagon[i].getterx3(), pentagon[i].gettery3()));
			pentagon1.setPoint(3, Vector2f(pentagon[i].getterx4(), pentagon[i].gettery4()));
			pentagon1.setPoint(4, Vector2f(pentagon[i].getterx5(), pentagon[i].gettery5()));

			pentagon[i].border();
			pentagon[i].move();
			pentagon1.move(pentagon[i].gettermovex(), pentagon[i].gettermovey());
			iHP[pentagon[i].getterhp()].setPosition(pentagon[i].gettermovex() - 5, pentagon[i].gettermovey() - 45);

			window.draw(iHP[pentagon[i].getterhp()]);
			window.draw(pentagon1);

		}

	}

	int Objects(RenderWindow& window, Triangle*& triangle, Square*& square, Pentagon*& pentagon, Texture Cloud[], Texture Heart) {
		int cloudcounter = 0;
		if (check(window) == 0)
			return 0;
		if (countertriangle > 0 && countersquare > 0)
			for (int newi = 0; newi < countertriangle; newi++)
			{
				for (int newj = 0; newj < countersquare; newj++)
				{
					if ((touch(triangle[newi], square[newj])) && (delay <= 0)) {

						if (rand() % 2)
						{
							Sprite iCloud[3];
							for (int i = 0; i < 3; i++) {
								iCloud[i].setTexture(Cloud[i]);
								iCloud[i].setPosition((square[newj].gettermovex() + triangle[newi].gettermovex()) / 2 - 15, (square[newj].gettermovey() + triangle[newi].gettermovey()) / 2 - 16);
							}

							int countercloudtime = 0;
							delay = 1000;
							while (countercloudtime < 10) {
								window.draw(iCloud[cloudcounter]);
								cloudcounter++;
								Sleep(100);
								if (cloudcounter == 3) {
									cloudcounter = 0;
								}
								countercloudtime++;
								window.display();
							}
							triangle[newi].setterhp(triangle[newi].getterhp() + 1);
							square[newj].setterhp(square[newj].getterhp() + 1);

							if (triangle[newi].getterhp() == 3)
							{

								triangle = triangle->delmas(triangle, countertriangle);
								std::cout << countertriangle << countersquare << std::endl;


							}
							if (square[newj].getterhp() == 3)
							{
								square = square->delmas(square, countersquare);
								int i = 100;
								int j = 100;

							}


						}
						else
						{
							Sprite iHeart;
							iHeart.setTexture(Heart);
							int countercloudtime = 0;
							delay = 1000;
							while (countercloudtime < 10) {

								iHeart.setPosition((square[newj].gettermovex() + triangle[newi].gettermovex()) / 2 - 18 + rand() % 8, (square[newj].gettermovey() + triangle[newi].gettermovey()) / 2 - 19 + rand() % 8);
								window.draw(iHeart);
								Sleep(40);

								Sleep(100);

								countercloudtime++;
								window.display();
							}

							if (rand() % 4 >= 1)
							{
								if (rand() % 2)
								{
									int exsisti = triangle->checkforexistence(triangle, countertriangle);
									countertriangle++;
									counterofall++;
									triangle = triangle->increasemas(triangle, countertriangle, exsisti);
								}
								else
								{
									int exsisti = square->checkforexistence(square, countersquare);
									countersquare++;
									counterofall++;
									square = square->increasemas(square, countersquare, exsisti);
								}
							}
							else
							{
								int exsisti = pentagon->checkforexistence(pentagon, counterpentagon);
								counterpentagon++;
								counterofall++;
								pentagon = pentagon->increasemas(pentagon, counterpentagon, exsisti);
							}

						}


					}
				}
			}

		if (check(window) == 0)
			return 0;
		if (countertriangle > 0 && counterpentagon > 0)
			for (int newi = 0; newi < countertriangle; newi++)
			{
				for (int newj = 0; newj < counterpentagon; newj++)
				{
					if ((touch(triangle[newi], pentagon[newj])) && (delay <= 0)) {
						if (rand() % 2)
						{
							Sprite iCloud[3];
							for (int i = 0; i < 3; i++) {
								iCloud[i].setTexture(Cloud[i]);
								iCloud[i].setPosition((pentagon[newj].gettermovex() + triangle[newi].gettermovex()) / 2 - 15, (pentagon[newj].gettermovey() + triangle[newi].gettermovey()) / 2 - 16);
							}

							int countercloudtime = 0;
							delay = 1000;
							while (countercloudtime < 10) {
								window.draw(iCloud[cloudcounter]);
								cloudcounter++;
								Sleep(100);
								if (cloudcounter == 3) {
									cloudcounter = 0;
								}
								countercloudtime++;
								window.display();
							}
							triangle[newi].setterhp(triangle[newi].getterhp() + 1);
							pentagon[newj].setterhp(pentagon[newj].getterhp() + 1);

							if (triangle[newi].getterhp() == 3)
							{

								triangle = triangle->delmas(triangle, countertriangle);
								std::cout << countertriangle << counterpentagon << std::endl;


							}
							if (pentagon[newj].getterhp() == 3)
							{
								pentagon = pentagon->delmas(pentagon, counterpentagon);
								int i = 100;
								int j = 100;


							}


						}
						else
						{
							Sprite iHeart;
							iHeart.setTexture(Heart);
							int countercloudtime = 0;
							delay = 1000;
							while (countercloudtime < 10) {

								iHeart.setPosition((pentagon[newj].gettermovex() + triangle[newi].gettermovex()) / 2 - 18 + rand() % 8, (pentagon[newj].gettermovey() + triangle[newi].gettermovey()) / 2 - 19 + rand() % 8);
								window.draw(iHeart);
								Sleep(40);

								Sleep(100);

								countercloudtime++;
								window.display();
							}
							if (rand() % 2)
							{
								int exsisti = triangle->checkforexistence(triangle, countertriangle);
								countertriangle++;
								counterofall++;
								triangle = triangle->increasemas(triangle, countertriangle, exsisti);
							}
							else
							{
								int exsisti = pentagon->checkforexistence(pentagon, counterpentagon);
								counterpentagon++;
								counterofall++;
								pentagon = pentagon->increasemas(pentagon, counterpentagon, exsisti);
							}

						}


					}
				}
			}

		if (check(window) == 0)
			return 0;
		if (counterpentagon > 0 && countersquare > 0)
			for (int newi = 0; newi < counterpentagon; newi++)
			{
				for (int newj = 0; newj < countersquare; newj++)
				{
					if ((touch(square[newj], pentagon[newi])) && (delay <= 0)) {
						if (rand() % 2)
						{
							Sprite iCloud[3];
							for (int i = 0; i < 3; i++) {
								iCloud[i].setTexture(Cloud[i]);
								iCloud[i].setPosition((square[newj].gettermovex() + pentagon[newi].gettermovex()) / 2 - 15, (square[newj].gettermovey() + pentagon[newi].gettermovey()) / 2 - 16);
							}

							int countercloudtime = 0;
							delay = 1000;
							while (countercloudtime < 10) {
								window.draw(iCloud[cloudcounter]);
								cloudcounter++;
								Sleep(100);
								if (cloudcounter == 3) {
									cloudcounter = 0;
								}
								countercloudtime++;
								window.display();
							}
							pentagon[newi].setterhp(pentagon[newi].getterhp() + 1);
							square[newj].setterhp(square[newj].getterhp() + 1);

							if (pentagon[newi].getterhp() == 3)
							{

								pentagon = pentagon->delmas(pentagon, counterpentagon);
								std::cout << counterpentagon << countersquare << std::endl;


							}
							if (square[newj].getterhp() == 3)
							{
								square = square->delmas(square, countersquare);
								int i = 100;
								int j = 100;


							}


						}
						else
						{
							Sprite iHeart;
							iHeart.setTexture(Heart);
							int countercloudtime = 0;
							delay = 1000;
							while (countercloudtime < 10) {

								iHeart.setPosition((square[newj].gettermovex() + pentagon[newi].gettermovex()) / 2 - 18 + rand() % 8, (square[newj].gettermovey() + pentagon[newi].gettermovey()) / 2 - 19 + rand() % 8);
								window.draw(iHeart);
								Sleep(40);

								Sleep(100);

								countercloudtime++;
								window.display();
							}
							if (rand() % 2)
							{
								int exsisti = pentagon->checkforexistence(pentagon, counterpentagon);
								counterpentagon++;
								counterofall++;
								pentagon = pentagon->increasemas(pentagon, counterpentagon, exsisti);
							}
							else
							{
								int exsisti = square->checkforexistence(square, countersquare);
								countersquare++;
								counterofall++;
								square = square->increasemas(square, countersquare, exsisti);
							}

						}


					}
				}
			}
	}


int check(RenderWindow& window) {

	if (counterofall == 10)
	{
		Texture exit1;
		exit1.loadFromFile("images/exit1.png");
		Sprite exxit1(exit1);
		window.draw(exxit1);
		window.display();
		Sleep(5000);
		return 0;
	}

	if (counterofall == 1 || counterofall == 0)
	{
		Texture exit3;
		exit3.loadFromFile("images/exit3.png");
		Sprite exxit3(exit3);
		window.draw(exxit3);
		window.display();
		Sleep(5000);
		return 0;
	}

	if (counterpentagon == counterofall || countersquare == counterofall || countertriangle == counterofall)
	{
		Texture exit2;
		exit2.loadFromFile("images/exit2.png");
		Sprite exxit2(exit2);
		window.draw(exxit2);
		window.display();
		Sleep(5000);
		return 0;
	}
}

void menu(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/start.png");
	menuTexture2.loadFromFile("images/exit.png");
	menuBackground.loadFromFile("images/fonmenu.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(535, 400);
	menu2.setPosition(558, 500);
	//	menuBg.setPosition(0, 0);

		//////////////////////////////лемч///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menuNum = 0;


		if (IntRect(535, 400, 230, 80).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Red); menuNum = 1; }
		if (IntRect(558, 500, 230, 80).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;

			if (menuNum == 2) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);

		window.draw(menu1);
		window.draw(menu2);
		window.display();
	}
}