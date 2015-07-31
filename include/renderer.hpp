#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "base.hpp"

class Geometry;
class PerspectiveCamera;

class Renderer{
public:
    void renderDepth(cil::CImg<unsigned char>&, Geometry&, PerspectiveCamera&, double maxDepth);
};


#endif // RENDERER_HPP
