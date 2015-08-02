#include "union.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "ray.hpp"
#include "intersect_result.hpp"
#include "vector.hpp"
#include "material.hpp"

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
            //printf("%f,%f,%f == %f,%f\n",ray->getDirection()->x(),ray->getDirection()->y(),ray->getDirection()->z(),minDistance, result->getGeometry()->getMaterial()->getReflectiveness());
        }
    }
    return minResult;
};
