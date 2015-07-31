#ifndef BASE_HPP
#define BASE_HPP

#include <memory>
#include <stdio.h>
#include <string>
#include <math.h>
#include "CImg.h"

class IntersectResult;
class Geometry;
class Vector;
class Sphere;
class Ray;

typedef std::shared_ptr<IntersectResult> PtrIntersectResult;
typedef std::shared_ptr<Geometry> PtrGeometry;
typedef std::shared_ptr<Vector> PtrVector;
typedef std::shared_ptr<Sphere> PtrSphere;
typedef std::shared_ptr<Ray> PtrRay;

constexpr double PI  =3.141592653589793238463;

#endif // BASE_HPP
