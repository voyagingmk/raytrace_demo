#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "base.hpp"

class Geometry: public std::enable_shared_from_this<Geometry>{
public:
    virtual void init() = 0;
    virtual PtrIntersectResult intersect(PtrRay) = 0;
};

#endif // GEOMETRY_HPP
