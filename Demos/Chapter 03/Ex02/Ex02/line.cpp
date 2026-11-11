#include <iostream>
#include "line.h"

namespace Drawing
{
	void Line::MoveTo(const Point &newLocation)
	{
		m_topLeft = newLocation;
	}
	
	void Line::Paint()const
	{
		std::cout << "Line[" << m_topLeft << "; " << m_bottomRight << "]\n";
	}
}