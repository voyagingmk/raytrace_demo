#include "base.hpp"

class PerspectiveCamera {
	PtrVector m_eye;
	PtrVector m_front;
	PtrVector m_up;
	PtrVector m_refUp;
	PtrVector m_right;
	double m_fov;
	double m_fovScale;
public:
	PerspectiveCamera(PtrVector eye, PtrVector front, PtrVector up, double fov);
	void init();
	PtrRay generateRay(double x, double y);
};
