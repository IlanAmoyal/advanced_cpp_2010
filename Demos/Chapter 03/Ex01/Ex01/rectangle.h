#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "shape.h"
#include "point.h"
#include "size.h"

namespace Drawing
{
	class Rectangle : public Shape
	{
	private:
		Point m_location;
		Size m_size;
		
	public:
		Rectangle() : m_location(), m_size() {}
		Rectangle(const Point &location, const Size &size) : m_location(location), m_size(size) {}
		Rectangle(int left, int top, int cx, int cy) : m_location(left, top), m_size(cx, cy) {}
		virtual void MoveTo(const Point &newLocation);
		virtual void Paint()const;
	};
}

#endif // RECTANGLE_H