#ifndef PLANE_HPP
#define PLANE_HPP

#include "base.hpp"
#include "geometry.hpp"

class Plane:public Geometry{
    PtrVector m_normal;
    double m_distance;
    PtrVector m_position;
public:
	Plane(PtrVector normal, double distance);
	Plane(const Plane &);
	Plane operator = (const Plane&);
	virtual void init();
	virtual PtrIntersectResult intersect(PtrRay);
	inline PtrVector getNormal() const {return m_normal;}
	inline PtrVector getPosition() const {return m_position;}
	inline double getDistance() const {return m_distance;}
};

#endif // PLANE_HPP
