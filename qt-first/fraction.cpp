#include <QString>
#include "fraction.h"

int Fraction::s_assigns = 0;
int Fraction::s_copies = 0;
int Fraction::s_ctors = 0;

Fraction::Fraction(int n, int d)
    : m_Numerator(n), m_Denominator(d)
{
    // cout << "invoke constractor: " <<
}

Fraction::Fraction(const Fraction &other)
    : m_Numerator(other.m_Numerator), m_Denominator(other.m_Denominator)
{
    ++s_copies;
}

Fraction& Fraction::operator = (const Fraction& other)
{
    if (this != &other)
    {
        m_Numerator = other.m_Numerator;
        m_Denominator = other.m_Denominator;
        ++s_assigns;
    }
    return *this;
}

void Fraction::set(int nn, int nd)
{
    m_Numerator = nn;
    m_Denominator = nd;
}

double Fraction::toDouble() const
{
    return 1.0 * m_Numerator / m_Denominator;
}

QString Fraction::toString() const
{
    return QString("%1 / %2").arg(m_Numerator).arg(m_Denominator);
}
