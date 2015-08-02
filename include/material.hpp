#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "base.hpp"


class Material: public std::enable_shared_from_this<Material>{
protected:
    double m_reflectiveness;
public:
	Material(double reflectiveness):m_reflectiveness(reflectiveness){};
    virtual PtrColor sample(PtrRay ray, PtrVector position, PtrVector normal) = 0;
    inline double getReflectiveness(){ return m_reflectiveness; };
public:
    static PtrVector LightDir;
    static PtrColor LightColor;
};

class CheckerMaterial: public Material{
    double m_scale;
public:
    CheckerMaterial(double scale, double reflectiveness=0);
    PtrColor sample(PtrRay ray, PtrVector position, PtrVector normal);
};


class PhongMaterial: public Material{
    PtrColor m_diffuse, m_specular;
    int m_shininess;
public:
    PhongMaterial(PtrColor diffuse, PtrColor specular, int shininess, double reflectiveness=0);
    PtrColor sample(PtrRay ray, PtrVector position, PtrVector normal);
    inline PtrColor getDiffuse(){ return m_diffuse; };
    inline PtrColor getSpecular(){ return m_specular; };
};

#endif // MATERIAL_HPP
