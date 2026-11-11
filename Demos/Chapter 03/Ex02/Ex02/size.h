#ifndef SIZE_H
#define SIZE_H

#include <iostream>

namespace Drawing
{
	class Size
	{
	private:
		int m_cx, m_cy;
		
	public:
		Size() : m_cx(0), m_cy(0) {}
		Size(int s) : m_cx(s), m_cy(s) {}
		Size(int cx, int cy) : m_cx(cx), m_cy(cy) {}
		int get_cx() const {return m_cx; }
		void set_cx(int cx) { m_cx = cx; }
		int get_cy() const {return m_cy; }
		void set_cy(int cy) { m_cy = cy; }
		Size operator+(const Size &sz)const;
		const Size& operator+=(const Size &sz);
		friend std::ostream &operator<<(std::ostream &o, const Size &sz);
		
	};
}

#endif // SIZE_H