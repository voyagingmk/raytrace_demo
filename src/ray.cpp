#include "ray.hpp"
#include <vector.hpp>

Ray::Ray(PtrVector origin, PtrVector direction)
    : m_origin(origin)
    , m_direction(direction)
{
}

Vector&& Ray::getPoint(double t)
{
    return m_origin + m_direction * t;
}