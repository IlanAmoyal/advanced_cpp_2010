#include <iostream>
#include "circle.h"

namespace Drawing
{
	void Circle::MoveTo(const Point &newLocation)
	{
		m_location = newLocation;
	}
	
	void Circle::Paint() const
	{
		std::cout << "Circle[" << m_location << "; " << m_radius << "]\n";
	}
}