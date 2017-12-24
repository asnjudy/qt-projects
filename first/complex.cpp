#include "complex.h"
#include <iostream>
#include <sstream>

using namespace std;

Complex::Complex() : m_R(0.0), m_I(0.0) {}

Complex::Complex(double realPart) : m_R(realPart), m_I(0.0) {}

Complex::Complex(double realPart, double imPart) : m_R(realPart), m_I(imPart) {}

string Complex::toString() const
{
    ostringstream strbuf;
    strbuf << '(' << m_R << ", " << m_I << ')';
    return strbuf.str();
}




