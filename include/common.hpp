#include "geometry.hpp"
#include "vector.hpp"


class IntersectResult{
	Geometry* m_geometry;
	double m_distance;
	Vector m_position;
	Vector m_normal;
public:
	IntersectResult();
	
public:
	static IntersectResult NoHit;
};
