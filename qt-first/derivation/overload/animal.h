#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
public:
	Animal();
	Animal(int height, int weight);
	~Animal();
private:
	int m_Height;
	int m_Weight;
};

class Fish : public Animal 
{
public:
	Fish();
	Fish(int height, int weight);
	~Fish();
};

#endif // !ANIMAL_H

