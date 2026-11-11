#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include "point.h"

namespace Drawing
{
	class Line : public Shape
	{
	private:
		Point m_topLeft, m_bottomRight;
		
	public:
		Line() : m_topLeft(), m_bottomRight() {}
		Line(const Point &topLeft, const Point &bottomRight) : m_topLeft(topLeft), m_bottomRight(bottomRight) {}
		Line(int left, int top, int right, int bottom) : m_topLeft(left, top), m_bottomRight(right, bottom) {}
		virtual void MoveTo(const Point &newLocation);
		virtual void Paint()const;
	};
}

#endif // LINE_H