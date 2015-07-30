class Vector {
private:
	double m_x, m_y, m_z;
public:
	Vector();
	Vector(const double x, const double y, const double z);
	Vector(const Vector &);
	Vector(Vector &&);
	Vector& operator = (Vector&&);
	~Vector();
	Vector&& operator + (const Vector&);
	Vector&& operator - (const Vector&);
	Vector&& operator * (double f);
	Vector&& operator / (double f);
	Vector&& operator - ();
	bool operator == (const Vector& v);
	double dot (const Vector&);
	Vector&& cross(const Vector&);
	inline double x() const;
	inline double y() const;
	inline double z() const;
	inline double length();
	inline double squareLength();
	Vector&& normalize();
	Vector& swap(Vector&);
public:
	static Vector Zero;
};
