#include <iostream>
#include "drawing.h"

using namespace std;
using namespace Drawing;

int main(int argc, char **argv)
{
	Line l = Line(2,3,4,5);
	Rectangle r = Rectangle(5,6,7,8);
	Circle c = Circle(20, 30, 5);
	
	cout << "using pointers...\n";
	Shape *pShapes[3] = {&l, &r, &c};
	for(int i = 0; i < 3; i++)
	{
		pShapes[i]->Paint();
		pShapes[i]->MoveTo(Point(100,200));
		pShapes[i]->Paint();
	}
	
	cout << "\n\nusing references...\n";
	Shape &shape1 = l;
	Shape &shape2 = r;
	Shape &shape3 = c;
	shape1.Paint();
	shape2.Paint();
	shape3.Paint();
	
	cout << "\n\nusing objects...\n";
	Shape shapes[] = {l, r, c};
	for(int i = 0; i < 3; i++)
	{
		shapes[i].Paint();
	}
}