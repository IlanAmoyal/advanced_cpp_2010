#include "point.h"

namespace Drawing
{
	Point Point::operator+(const Point &point)const
	{
		return Point(m_left + point.m_left, m_top + point.m_top);
	}
	
	Point Point::operator+(const Size &sz)const
	{
		return Point(m_left + sz.get_cx(), m_top + sz.get_cy());
	}
	
	const Point& Point::operator+=(const Point &point)
	{
		m_left += point.m_left;
		m_top += point.m_top;
		return *this;
	}

	std::ostream &operator<<(std::ostream &o, const Point &point)
	{
		o << "(" << point.m_left << ", " << point.m_top << ")";
		return o;
	}
}