#include <SFML/Graphics.hpp>
#include <ctime>
#include <windows.h>
#include <iostream>
#include <math.h>

using namespace sf;

extern int masbottom[3];
extern int masright[3];
extern int masleft[3];
extern int masup[3];
extern int counter;
extern int icounter;

extern int counterofall;

extern int countertriangle;
extern int countersquare;
extern int counterpentagon;
extern const int radius;
extern int delay;

class Point
{
public:
	virtual int getterx1() = 0;
	virtual int gettery1() = 0;

	Point(int x1, int y1);
	Point();
protected:
	int x1;
	int y1;
};

class Triangle : public Point {

public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int movex, int movey);
	Triangle();
	Triangle(const Triangle& triangle);
	Triangle* increasemas(Triangle mas[], int countertriangle, int exsisti);
	Triangle* delmas(Triangle mas[], int& countertriangle);

	int checkforexistence(Triangle mas[], int countertriangle);
	virtual int getterx1();
	virtual int getterx2();
	virtual int getterx3();
	virtual int gettery1();
	virtual int gettery2();
	virtual int gettery3();
	virtual int gettermovex();
	virtual int gettermovey();
	virtual int gettercolorR();
	virtual int gettercolorG();
	virtual int gettercolorB();
	virtual int gettercenterx();
	virtual int gettercentery();
	virtual int getterhp();
	virtual void setterhp(int hp);
	virtual void border();
	virtual void move();
protected:
	int x2;
	int x3;
	int y2;
	int y3;
	int centerx;
	int centery;
	int hp;
	int color[3];
	int movex;
	int movey;
	int temp;

};




class Square : public Triangle {
public:
	Square(int x1, int y1, int x2, int y2, int x3, int y3, int movex, int movey, int x4, int y4);
	Square();
	Square(const Square& square);

	Square* increasemas(Square mas[], int countertsquare, int exsisti);
	Square* delmas(Square mas[], int& countertsquare);
	int checkforexistence(Square mas[], int countertsquare);

	virtual int getterx4();
	virtual int gettery4();
protected:
	int x4;
	int y4;
};



class Pentagon : public Square {

public:
	Pentagon(int x1, int y1, int x2, int y2, int x3, int y3, int movex, int movey, int x4, int y4, int x5, int y5);
	Pentagon();
	virtual int getterx5();
	virtual int gettery5();
	Pentagon* increasemas(Pentagon mas[], int countertpentagon, int exsisti);
	Pentagon* delmas(Pentagon mas[], int& countertpentagon);
	int checkforexistence(Pentagon mas[], int counterpentagon);
protected:
	int x5;
	int y5;
};

template <typename T, typename T1>
int touch(T& obj1, T1& obj2) {
	unsigned int katet1, katet2;
	katet1 = obj1.gettermovex() - obj2.gettermovex();
	katet2 = obj1.gettermovey() - obj2.gettermovey();
	if (sqrt(katet1 * katet1 + katet2 * katet2) <= (radius + radius))
	{
		return 1;
	}
	else
		return 0;
}
void draw(RenderWindow& window, Triangle*& triangle, Square*& square, Pentagon*& pentagon, Sprite iHP[]);
int Objects(RenderWindow& window, Triangle*& triangle, Square*& square, Pentagon*& pentagon, Texture Cloud[], Texture Heart);
int check(RenderWindow& window);
void menu(RenderWindow& window);