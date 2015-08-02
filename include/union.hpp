#ifndef UNION_HPP
#define UNION_HPP

#include "base.hpp"
#include "geometry.hpp"

class Union:public Geometry{
    std::vector<PtrGeometry> m_geometries;
public:
    Union(std::vector<PtrGeometry>);
    void init();
    PtrIntersectResult intersect(PtrRay ray);
};


#endif // UNION_HPP
