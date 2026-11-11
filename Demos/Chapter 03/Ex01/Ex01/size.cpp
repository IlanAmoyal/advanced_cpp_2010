#include "size.h"

namespace Drawing
{
	Size Size::operator+(const Size &sz)const
	{
		return Size(m_cx + sz.m_cx, m_cy + sz.m_cy);
	}
	
	const Size& Size::operator+=(const Size &sz)
	{
		m_cx += sz.m_cx;
		m_cy += sz.m_cy;
		return *this;
	}

	std::ostream &operator<<(std::ostream &o, const Size &sz)
	{
		o << "{" << sz.m_cx << ", " << sz.m_cy << "}";
		return o;
	}
}