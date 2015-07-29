#include "ray.hpp"
class Sphere:public Geometry{
public:
	Sphere(Vector center, Vector radius);
	Sphere(Sphere &);
	Sphere operator = (const Sphere&);
	void init();
	bool intersect(Ray&);
}