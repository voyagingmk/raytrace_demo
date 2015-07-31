#include "sphere.hpp"
#include "vector.hpp"
#include "ray.hpp"
#include "intersect_result.hpp"


Sphere::Sphere(PtrVector center, double radius):m_center(center), m_radius(radius){
}
Sphere::Sphere(Sphere& s){
    m_center = std::make_shared<Vector>(*s.getCenter());
    m_radius = s.getRadius();
}
Sphere Sphere::operator = (const Sphere& s){
    m_radius = s.getRadius();
    m_center = std::make_shared<Vector>(*s.getCenter());
    return *this;
}
void Sphere::init(){
    m_sqrRadius = m_radius * m_radius;
}
PtrIntersectResult Sphere::intersect(PtrRay ray){
    Vector&& v = *(ray->getOrigin()) - (*m_center);
    double a0 = v.squareLength() - m_sqrRadius;
    double DdotV = ray->getDirection()->dot(v);
    printf("a0 = %f\n", a0);
    printf("DdotV = %f\n", DdotV);
    if (DdotV <= 0) {
        double discr = DdotV * DdotV - a0;
        printf("discr = %f\n", discr);
        if (discr >= 0) {
            auto distance = -DdotV - sqrtf(discr);
            printf("distance = %f\n", distance);
            auto position = ray->getPoint(distance);
            auto normal = (*position - *m_center).normalize();
            return std::make_shared<IntersectResult>(IntersectResult(shared_from_this(), distance, *position, normal));
        }
    }

    return IntersectResult::NoHit;
}
