#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

namespace Drawing
{
	class Shape
	{
	public:
		virtual void Paint()const = 0;
		virtual void MoveTo(const Point &newLocation) = 0;
	};
}

#endif // SHAPE_H