#include "material.hpp"
#include "vector.hpp"
#include "color.hpp"
#include "ray.hpp"

CheckerMaterial::CheckerMaterial(double scale, double reflectiveness):
    Material(reflectiveness),
	m_scale(scale){
};

PtrColor CheckerMaterial::sample(PtrRay ray, PtrVector position, PtrVector normal){
    return abs( ( int(std::floor(position->x() * 0.1)) + int(std::floor(position->z() * m_scale)) ) % 2) < 1 ? Color::Black : Color::White;
};


PhongMaterial::PhongMaterial(PtrColor diffuse, PtrColor specular, int shininess, double reflectiveness):
    Material(reflectiveness),
	m_diffuse(diffuse),
    m_specular(specular),
    m_shininess(shininess){

};

PtrColor PhongMaterial::sample(PtrRay ray, PtrVector position, PtrVector normal){
    double NdotL = normal->dot(*LightDir);
    Vector&& H = (*LightDir - *(ray->getDirection())).normalize();
    double NdotH = normal->dot(H);
    Color&& diffuseTerm = *m_diffuse * ( std::max(NdotL, 0.0) );
    Color&& specularTerm = *m_specular * (double)(std::pow(std::max(NdotH, 0.0), m_shininess));
    Color result = Color::White->modulate(diffuseTerm + specularTerm);
    return std::make_shared<Color>(result);
};


PtrVector Material::LightDir = std::make_shared<Vector>(Vector(1, 1, 1).normalize());
PtrColor Material::LightColor = Color::White;
