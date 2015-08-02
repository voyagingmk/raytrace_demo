#include "vector.hpp"
#include <algorithm>

Vector::Vector():m_x(0), m_y(0), m_z(0) {
     debug("Vector default created.");
};

Vector::Vector(const double x, const double y, const double z):m_x(x), m_y(y), m_z(z) {
    debug("Vector param created.");
};

Vector::Vector(Vector && v):m_x(0),m_y(0),m_z(0) {
	m_x = v.m_x;
	m_y = v.m_y;
	m_z = v.m_z;
	v.m_x = 0;
	v.m_y = 0;
	v.m_z = 0;
	debug("Vector move created.");
}

Vector::Vector(const Vector & v) {
	m_x = v.x();
	m_y = v.y();
	m_z = v.z();
	debug("Vector copy created.");
}

Vector::~Vector() {
    debug("Destroyed.");
}

Vector& Vector::operator = (const Vector& v) {
	m_x = v.x();
	m_y = v.y();
	m_z = v.z();
	debug("Vector copy assigned.");
	return *this;
}
Vector& Vector::operator = (Vector&& v) {
	v.swap(*this);
	debug("Vector move assigned.");
	return *this;
}


Vector Vector::operator + (const Vector& v) {
	return Vector(m_x + v.x(), m_y + v.y(), m_z + v.z());
}
Vector Vector::operator - (const Vector& v) {
	return Vector(m_x - v.x(), m_y - v.y(), m_z - v.z());
}
Vector Vector::operator - () {
	return Vector(-m_x, -m_y, -m_z);
}
Vector Vector::operator * (double f) {
	return Vector(m_x * f, m_y * f, m_z * f);
}

Vector Vector::operator / (double f) {
	if(f==0)
		return *this;
	return Vector(m_x / f, m_y / f, m_z / f);
}

bool Vector::operator == (const Vector& v) {
	return m_x == v.x() && m_y == v.y() && m_z == v.z();
}

Vector Vector::cross(const Vector& v) {
	Vector && res =  Vector(-m_z * v.y() + m_y * v.z(), m_z * v.x() - m_x * v.z(), - m_y * v.x() + m_x * v.y());
	return res;
}


Vector& Vector::swap(Vector& v) {
	std::swap(*this, v);
	return *this;
}

double Vector::dot(const Vector& v){
    return m_x * v.x() + m_y * v.y() + m_z * v.z();
}

Vector Vector::normalize(){
   double inv = 1.0 / length();
   return Vector(m_x * inv, m_y * inv, m_z * inv);
}

PtrVector Vector::Zero = std::make_shared<Vector>(0,0,0);
