#include "animal.h"
#include <QString>
#include "std2qt.h"

using namespace std2qt;

Animal::Animal()
{
	cout << this << " Animal::Animal()" << endl;
}
Animal::Animal(int height, int weight)
	: m_Height(height), m_Weight(weight)
{
	cout << this << QString(" Animal::Animal(%1, %2)").arg(height).arg(weight) << endl;
}
Animal::~Animal()
{
	cout << this << " Animal::~Animal()" << endl;
}


Fish::Fish()
{
	cout << this << " Fish::Fish()" << endl;
}
Fish::Fish(int height, int weight)
	: Animal(height, weight)
{
	cout << this << QString(" Fish::Fish(%1, %2)").arg(height).arg(weight) << endl;
}
Fish::~Fish()
{
	cout << this << " Fish::~Fish()" << endl;
}
