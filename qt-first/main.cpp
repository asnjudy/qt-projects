#include <iostream>
#include <QString>

extern void testAccount();
extern void testAnimal();
extern void testJointAccout();
extern void testJointAccout();
extern void testBank();
// �����Զ���������в�����ȡ��
extern void testArgumentList(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	// testAccount();
	// testAnimal();
	// testJointAccout();
	// testBank();

	
	testArgumentList(argc, argv);

	system("pause");
     return 0;
}
