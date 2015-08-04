#include "color.hpp"

Color::Color(){
};

Color::Color(double r, double g, double b){
    m_rgb[0] = r;
    m_rgb[1] = g;
    m_rgb[2] = b;
};

Color::Color(const Color& c){
    m_rgb[0] = c.r();
    m_rgb[1] = c.g();
    m_rgb[2] = c.b();
};
Color::Color(Color&& c){
    m_rgb[0] = c.r();
    m_rgb[1] = c.g();
    m_rgb[2] = c.b();
};

Color& Color::operator = (const Color& c){
    m_rgb[0] = c.r();
    m_rgb[1] = c.g();
    m_rgb[2] = c.b();
    return *this;
};

Color& Color::operator = (Color&& c){
    m_rgb[0] = c.r();
    m_rgb[1] = c.g();
    m_rgb[2] = c.b();
    return *this;
};

Color::~Color(){};

Color Color::operator + (const Color& c){
    return Color(m_rgb[0] + c.r(), m_rgb[1] + c.g(), m_rgb[2] + c.b());
};

Color Color::operator - (const Color& c){
    return Color(m_rgb[0] - c.r(), m_rgb[1] - c.g(), m_rgb[2] - c.b());
};

Color Color::operator * (double f){
    return Color(m_rgb[0] * f, m_rgb[1] * f, m_rgb[2] * f);
};

Color Color::operator / (double f){
    return Color(m_rgb[0] / f, m_rgb[1] / f, m_rgb[2] / f);
};

bool Color::operator == (const Color& c){
    return m_rgb[0] == c.r() && m_rgb[1] == c.g() && m_rgb[2] == c.b();
};
Color Color::modulate(const Color& c){
    return Color(m_rgb[0] * c.r(), m_rgb[1] * c.g(), m_rgb[2] * c.b());
};

const PtrColor Color::Black = std::make_shared<Color>(0, 0, 0);
const PtrColor Color::White = std::make_shared<Color>(1.0, 1.0, 1.0);
const PtrColor Color::Red = std::make_shared<Color>(1.0, 0, 0);
const PtrColor Color::Green = std::make_shared<Color>(0, 1.0, 0);
const PtrColor Color::Blue = std::make_shared<Color>(0,0,1.0);

