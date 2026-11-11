#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"

namespace Drawing
{
	class Circle : public Shape
	{
	private:
		Point m_location;
		int m_radius;
		
	public:
		Circle() : m_location(0), m_radius(0) {}
		Circle(int radius) : m_location(), m_radius(radius) {}
		Circle(const Point &location, int radius) : m_location(location), m_radius(radius) {}
		Circle(int left, int top, int radius) : m_location(left, top), m_radius(radius) {}
		virtual void MoveTo(const Point &newLocation);
		virtual void Paint()const;
	};
}

#endif // CIRCLE_H