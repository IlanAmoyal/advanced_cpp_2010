#include "rectangle.h"

namespace Drawing
{
	void Rectangle::MoveTo(const Point& newLocation)
	{
		m_location = newLocation;
	}
	
	void Rectangle::Paint()const
	{
		std::cout << "Rectangle[" << m_location << "; " << m_size << "]\n";
	}
}