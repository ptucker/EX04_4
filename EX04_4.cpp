// EX04_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Rectangle2D
{
private:
	double x, y, width, height;

public:
	Rectangle2D()
	{
		x = 0; 
		y = 0; 
		width = 0;
		height = 0;
	}
	Rectangle2D(double Xcoord, double Ycoord, double wide, double high)
	{
		x = Xcoord;
		y = Ycoord;
		width = wide;
		height = high;
	}

	double getX() const { return x; }
	double getY() const { return y; }
	double setX(double x)
	{
		if (x > 0)
			this->x = x; 
	}
	double setY(double y) 
	{ 
		if (y > 0)
			this->y = y; 
	}

	double getHeight() const { return height; }
	double getWidth() const { return width; }
	double setHeight(double h) { height = h; }
	double setWidth(double w) { width = w; }

	double getArea() const {
		double area = this->height * this->width;
		return area;
	}
	
	double getPerimeter() const {
		double perimeter = (2 * this->width) + (2 * this->height);
		return perimeter;
	}
	
	bool contains(double x, double y) const {
		if (x < (this->x + (.5*this->width)) && x >(this->x - (.5*this->width)) && 
			y < (this->y + (.5*this->height)) && y >(this->y - (.5*this->height)))
			return true;
		else
			return false;
	}
	
	bool contains(const Rectangle2D &r) const {
		double x = r.getX();
		double y = r.getY();
		double width = r.getWidth();
		double height = r.getHeight();

		if ((x + (.5*width)) < (this->x + (.5*this->width)) && (x - (.5*width)) > (this->x - (.5*this->width)) &&
			(y + (.5*height)) < (this->y + (.5*this->height)) && (y - (.5*height)) > (this->y - (.5*this->height)))
			return true; 
		else
			return false;

	}
	
	bool overlaps(const Rectangle2D &r) const
	{
		double upperR_xForR = r.getX() + (0.5*r.getWidth());
		double upperR_yForR = r.getY() + (0.5*r.getHeight());
		double bottomL_xForR = r.getX() - (0.5*r.getWidth());
		double bottomL_yForR = r.getY() - (0.5*r.getHeight());
		
		double upperR_x = this->x + (0.5*this->width);
		double upperR_y = this->y + (0.5*this->height);
		double bottomL_x = this->x - (0.5*this->width);
		double bottomL_y = this->y - (0.5*this->height);

		if (upperR_xForR < bottomL_x)
			return false;
		else if (bottomL_xForR > upperR_x)
			return false;
		else if (upperR_yForR < bottomL_y)
			return false;
		else if (bottomL_yForR > upperR_y)
			return false;
		else
			return true;
	}
};


int main()
{
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);

	cout << "r1 - area = " << r1.getArea() << endl;
	cout << "r1 - perimeter = " << r1.getPerimeter() << endl;

	int check1 = r1.contains(3, 3);
	if (check1 == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	int check2 = r1.contains(r2);
	if (check2 == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	int check3 = r1.overlaps(r3);
	if (check3 == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;

    return 0;
}

