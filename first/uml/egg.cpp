#include "egg.h"
#include "chicken.h"

Egg::Egg()
{
}


/**
* @brief 获取蛋的父亲（鸡）
* @return 
*/
Chicken* Egg::getParent()
{
	return new Chicken();
}
