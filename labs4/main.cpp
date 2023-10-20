#include <iostream>
#include "cat.h"

void inc(int& a)
{
    a++;
    std::cout << a << "\n";
}

int main()
{
    char name1[] = "kitty cat";
    char name2[] = "catty kit";


    Cat *meow = new Cat(name1);
    Cat *peter = new Cat(name2);

    meow->print_name();
    peter->print_name();

}