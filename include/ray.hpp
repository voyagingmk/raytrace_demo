#ifndef RAY_HPP
#define RAY_HPP

#include "base.hpp"

class Ray{
	PtrVector m_origin;
	PtrVector m_direction;
public:
	Ray(PtrVector origin, PtrVector direction);
	PtrVector getPoint(double t);
	inline PtrVector getOrigin(){ return m_origin; };
	inline PtrVector getDirection(){ return m_direction; };
};

#endif // RAY_HPP
