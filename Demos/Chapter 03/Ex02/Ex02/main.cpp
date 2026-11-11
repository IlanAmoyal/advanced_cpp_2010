#include <iostream>
#include "drawing.h"

using namespace std;
using namespace Drawing;

int main(int argc, char **argv)
{
	Line l = Line(2,3,4,5);
	Rectangle r = Rectangle(5,6,7,8);
	Circle c = Circle(20, 30, 5);
	
	Shape *pShapes[3] = {&l, &r, &c};
	for(int i = 0; i < 3; i++)
	{
		pShapes[i]->Paint();
		pShapes[i]->MoveTo(Point(100,200));
		pShapes[i]->Paint();
	}
	
	Shape *shape = new Shape();
	//shape.Paint();
}