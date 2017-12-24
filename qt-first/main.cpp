#include <iostream>
#include <QString>

extern void testAccount();
extern void testAnimal();
extern void testJointAccout();
extern void testJointAccout();
extern void testBank();
// 测试自定义的命令行参数获取类
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
