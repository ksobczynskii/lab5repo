#include <string>
#include <vector>
#include <memory>
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{

    int a = 7;
    int b = 9;
    swap(a, b);
    int *dynint = new int(10);
    int *dyn2 = new int(17);

    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "dynint: " << *dynint << " dyn2: " << *dyn2 << std::endl;
    swap(dyn2, dynint);
    std::cout << "dynint: " << *dynint << " dyn2: " << *dyn2 << std::endl;
    delete dyn2;
    delete dynint;
    return 0;
}