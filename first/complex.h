#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>

using namespace std;

class Complex
{
public:
    Complex();
    Complex(double realPart);
    Complex(double realPart, double imPart);
    string toString() const;

private:
    double m_R, m_I;
};

#endif // COMPLEX_H
