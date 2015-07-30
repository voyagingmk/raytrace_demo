#include "perspectivecamera.hpp"
#include <cmath>

PerspectiveCamera::PerspectiveCamera(PtrVector eye, PtrVector front, PtrVector up, double fov)
    : m_eye(eye)
    , m_front(front)
    , m_refUp(up)
    , m_fov(fov)
{
}

void PerspectiveCamera::init(){
	m_right = (*m_front).cross(*m_refUp);
	m_up = (*m_right).cross(*m_front);
	m_fovScale = tan(m_fov * 0.5 * M_PI / 180.0) * 2;
}

Ray PerspectiveCamera::generateRay(double x, double y){
	Vector r = m_right * ( (x - 0.5) * m_fovScale );
	Vector u = m_up * ( (y - 0.5) * m_fovScale );
	return Ray(m_eye, (m_front+ r + u).normalize());
}
