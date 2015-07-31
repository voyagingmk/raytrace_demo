#include "intersect_result.hpp"
#include "vector.hpp"

IntersectResult::IntersectResult():
	m_geometry(nullptr),
	m_distance(0),
	m_position(Vector::Zero),
	m_normal(Vector::Zero){
};

IntersectResult::IntersectResult(PtrGeometry ptrGeo, double dis, PtrVector pos, PtrVector normal):
	m_geometry(ptrGeo),
	m_distance(dis),
	m_position(pos),
	m_normal(normal){
};

IntersectResult::IntersectResult(PtrGeometry ptrGeo, double dis, const Vector& pos, const Vector& normal):
	m_geometry(ptrGeo),
	m_distance(dis),
	m_position(std::make_shared<Vector>(pos)),
	m_normal(std::make_shared<Vector>(normal)){
};

PtrIntersectResult IntersectResult::NoHit = std::make_shared<IntersectResult>();
