#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "base.hpp"

class Geometry;
class PerspectiveCamera;

class Renderer{
public:
    void renderDepth(cil::CImg<unsigned char>&, Geometry&, PerspectiveCamera&, double maxDepth);
    void renderNormal(cil::CImg<unsigned char> &img, Geometry& scene, PerspectiveCamera& camera, double maxDepth);
    void rayTrace(cil::CImg<unsigned char> &img, Geometry& scene, PerspectiveCamera& camera);
	PtrColor rayTraceRecursive( PtrGeometry scene, PtrRay ray, int maxReflect);
	void rayTraceReflection(cil::CImg<unsigned char> &img, PtrGeometry scene, PerspectiveCamera& camera, int maxReflect, int x = 0, int y = 0, int w = 0, int h = 0);
};


#endif // RENDERER_HPP
