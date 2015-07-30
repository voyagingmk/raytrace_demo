#include "base.hpp"

class Ray{
	PtrVector m_origin;
	PtrVector m_direction;
public:
	Ray(PtrVector origin, PtrVector direction);
	PtrVector getPoint(double t);
};
