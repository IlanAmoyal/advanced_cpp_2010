#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

namespace Drawing
{
	class Shape
	{
	public:
		virtual void Paint()const;
		virtual void MoveTo(const Point &newLocation);
	};
}

#endif // SHAPE_H