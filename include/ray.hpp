#include<memory>

class Vector;

typedef shared_ptr<Vector*> PtrVector;
class Ray{
	PtrVector m_origin;
	PtrVector m_direction;
public:
	Ray(PtrVector origin, PtrVector direction);
	Vector&& getPoint(double t);
};