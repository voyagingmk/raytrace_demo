#include "material.hpp"
#include "vector.hpp"
#include "color.hpp"
#include "ray.hpp"

CheckerMaterial::CheckerMaterial(double scale, double reflectiveness):
    m_scale(scale),
    Material(reflectiveness){
};

PtrColor CheckerMaterial::sample(PtrRay ray, PtrVector position, PtrVector normal){
    return abs( ( int(std::floor(position->x() * 0.1)) + int(std::floor(position->z() * m_scale)) ) % 2) < 1 ? Color::Black : Color::White;
};


PhongMaterial::PhongMaterial(PtrColor diffuse, PtrColor specular, int shininess, double reflectiveness):
    m_diffuse(diffuse),
    m_specular(specular),
    m_shininess(shininess),
    Material(reflectiveness){

};

PtrColor PhongMaterial::sample(PtrRay ray, PtrVector position, PtrVector normal){
    double NdotL = normal->dot(*LightDir);
    //printf("NdotL=%f\n",NdotL);
    Vector&& H = (*LightDir - *(ray->getDirection())).normalize();
    double NdotH = normal->dot(H);
    //printf("NdotH=%f\n",NdotH);
    //printf("m_diffuse=%f,%f,%f\n",m_diffuse->r(),m_diffuse->g(),m_diffuse->b());
    Color&& diffuseTerm = *m_diffuse * ( std::max(NdotL, 0.0) );
    //printf("diffuseTerm=%f,%f,%f\n",diffuseTerm.r(),diffuseTerm.g(),diffuseTerm.b());
    Color&& specularTerm = *m_specular * (double)(std::pow(std::max(NdotH, 0.0), m_shininess));
    //printf("specularTerm=%f,%f,%f\n",specularTerm.r(),specularTerm.g(),specularTerm.b());
    Color result = Color::White->modulate(diffuseTerm + specularTerm);
    //printf("color=%f,%f,%f\n",result.r(),result.g(),result.b());
    return std::make_shared<Color>(result);
};


PtrVector Material::LightDir = std::make_shared<Vector>(Vector(1, 1, 1).normalize());
PtrColor Material::LightColor = Color::White;
