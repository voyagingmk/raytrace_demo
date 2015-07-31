#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "base.hpp"

class Vector {
private:
	double m_x, m_y, m_z;
public:
	Vector();
	Vector(const double x, const double y, const double z);
	Vector(const Vector &);
	Vector(Vector &&);
	Vector& operator = (const Vector&);
	Vector& operator = (Vector&&);
	~Vector();
	Vector operator + (const Vector&);
	Vector operator - (const Vector&);
	Vector operator * (double f);
	Vector operator / (double f);
	Vector operator - ();
	bool operator == (const Vector& v);
	double dot (const Vector&);
	Vector cross(const Vector&);
	inline double x() const{return m_x;};
	inline double y() const{return m_y;};
	inline double z() const{return m_z;};
	inline double length(){ return sqrt(m_x * m_x + m_y * m_y + m_z * m_z); };
	inline double squareLength(){ return m_x * m_x + m_y * m_y + m_z * m_z; };
	Vector normalize();
	Vector& swap(Vector&);
	void debug(){
        debug("");
    }
    void debug(std::string msg){
        //printf("%s [x, y, z = %f, %f, %f]\n", msg.c_str(), m_x, m_y, m_z);
    }
public:
	static PtrVector Zero;

};

#endif // VECTOR_HPP
