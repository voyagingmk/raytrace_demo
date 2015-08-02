
#include "plane.hpp"
#include "vector.hpp"
#include "ray.hpp"
#include "intersect_result.hpp"

Plane::Plane(PtrVector normal, double distance):
    m_normal(normal),
    m_distance(distance){

};

Plane::Plane(const Plane& p){
    m_normal = p.getNormal();
    m_distance = p.getDistance();
}
Plane Plane::operator = (const Plane& p){
    m_normal = p.getNormal();
    m_distance = p.getDistance();
}
void Plane::init(){
    m_position = std::make_shared<Vector>(*m_normal * m_distance);
}
PtrIntersectResult Plane::intersect(PtrRay ray){
    double dotA = ray->getDirection()->dot(*m_normal);
    if (dotA >= 0)
        return IntersectResult::NoHit;
    double dotB = m_normal->dot(*(ray->getOrigin()) - *m_position);
    double distance = -dotB / dotA;
    return std::make_shared<IntersectResult>(IntersectResult(shared_from_this(), distance, ray->getPoint(distance), m_normal));
}
