class Vector;
class Ray;

class PerspectiveCamera {
	Vector* m_eye;
	Vector* m_front;
	Vector* m_up;
	Vector* m_refUp;
	Vector* m_right;
	double m_fov;
	double m_fovScale;
public:
	PerspectiveCamera(Vector& eye, Vector& front, Vector& up, double fov);
	void init();
	Ray* generateRay(double x, double y);
};
