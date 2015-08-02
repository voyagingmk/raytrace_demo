#include "union.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "ray.hpp"
#include "intersect_result.hpp"

Union::Union( std::vector<PtrGeometry> geometries):m_geometries(geometries){
};

void Union::init() {
    for (auto p:m_geometries){
        p->init();
    }
};

PtrIntersectResult Union::intersect(PtrRay ray){
    double minDistance = std::numeric_limits<double>::max();
    auto minResult = IntersectResult::NoHit;
     for (auto p:m_geometries){
        auto result = p->intersect(ray);
        if (result->getGeometry() && result->getDistance() < minDistance) {
            minDistance = result->getDistance();
            minResult = result;
        }
    }
    return minResult;
};
