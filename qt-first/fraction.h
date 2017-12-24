#ifndef FRACTION_H
#define FRACTION_H

#include <QString>

class Fraction {

public:
    Fraction(int n, int d);
    Fraction(const Fraction& other);
    Fraction& operator = (const Fraction& other);
    Fraction multiply(Fraction f2);

    static QString report();

    void set(int numerator, int denominator);
    double toDouble() const;
    QString toString() const;

private:
    int m_Numerator;
    int m_Denominator;

    static int s_assigns;
    static int s_copies;
    static int s_ctors;
};
#endif // FRACTION_H
