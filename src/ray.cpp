#include "ray.hpp"
#include <vector.hpp>

Ray::Ray(PtrVector origin, PtrVector direction)
    : m_origin(origin)
    , m_direction(direction)
{
}

PtrVector Ray::getPoint(double t)
{
    PtrVector result = std::make_shared<Vector>((*m_origin) + (*m_direction) * t);
    return result;
}
