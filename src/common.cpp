#include "common.hpp"

IntersectResult::IntersectResult(): 
	m_geometry(nullptr),
	m_distance(0),
	m_position(Vector::Zero),
	m_normal(Vector::Zero){
};

IntersectResult IntersectResult::NoHit;