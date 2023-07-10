#include "BigInt.h"
int main()
{

    BigInt num1 ("1000");
    BigInt num2 ("500") ;
    BigInt soma= num1 + num2;
    BigInt sub = num1 - num2;
    BigInt mult= num1 * num2;
    BigInt div = num1 / num2;

    std::cout << soma.numero << std::endl;
    std::cout << sub.numero << std::endl;
    std::cout << mult.numero << std::endl;
    std::cout << div.numero << std::endl;

    return 0;
}
