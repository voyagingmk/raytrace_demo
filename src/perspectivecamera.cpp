#include "perspectivecamera.hpp"
#include <cmath>
#include <vector.hpp>
#include <ray.hpp>

PerspectiveCamera::PerspectiveCamera(PtrVector eye, PtrVector front, PtrVector up, double fov)
    : m_eye(eye)
    , m_front(front)
    , m_refUp(up)
    , m_fov(fov)
{
}

void PerspectiveCamera::init(){
	m_right = std::make_shared<Vector>(m_front->cross(*m_refUp));
	m_up = std::make_shared<Vector>(m_right->cross(*m_front));
	m_fovScale = tan(m_fov * 0.5 * PI / 180.0) * 2;
}

PtrRay PerspectiveCamera::generateRay(double x, double y){
	Vector&& r = (*m_right) * ( (x - 0.5) * m_fovScale );
	Vector&& u = (*m_up) * ( (y - 0.5) * m_fovScale );
	Vector&& v = (*m_front+ r + u).normalize();
	PtrRay ray = std::make_shared<Ray>(Ray(m_eye, std::make_shared<Vector>(v)));
	return ray;
}
