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
	void init();
	PtrIntersectResult intersect(PtrRay);
	PtrVector getCenter(){return m_center;}
	inline double getRadius(){return m_radius;}
};

#endif // SPHERE_HPP
