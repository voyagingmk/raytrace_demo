#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "base.hpp"
#include "geometry.hpp"

class Sphere:public Geometry{
    PtrVector m_center;
    double m_radius;
    double m_sqrRadius;
public:
	Sphere(PtrVector center, double radius);
	Sphere(Sphere &);
	Sphere operator = (const Sphere&);
	virtual void init();
	virtual PtrIntersectResult intersect(PtrRay);
	PtrVector getCenter() const {return m_center;}
	inline double getRadius() const {return m_radius;}
};

#endif // SPHERE_HPP
