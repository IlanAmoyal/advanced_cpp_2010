#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "size.h"

namespace Drawing
{
	class Point
	{
	private:
		int m_left;
		int m_top;
	
	public:
		Point() : m_left(0), m_top(0) {}
		Point(int x) : m_left(x), m_top(x) {}
		Point(int left, int top) : m_left(left), m_top(top) {}
		int get_left() const { return m_left; }
		void set_left(int left) { m_left = left; }
		int get_top() const { return m_top; }
		void set_top(int top) { m_top = top; }
		Point operator+(const Point &point)const;
		Point operator+(const Size &sz)const;
		const Point& operator+=(const Point &point);
		friend std::ostream &operator<<(std::ostream &o, const Point &point);
	};
}

#endif // POINT_H