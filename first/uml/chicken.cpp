#include "chicken.h"

Chicken::Chicken()
{

}

/**
 * @brief 鸡下蛋
 * @return
 */
Egg* Chicken::layEgg()
{
    return new Egg();
}
