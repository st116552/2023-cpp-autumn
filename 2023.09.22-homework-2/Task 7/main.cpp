#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    if (n == 100) 
    {
        std::cout << "C";
    }
    else 
    {
        if (n >= 90)
        {
            std::cout << "XC";
            n = n - 90;
        }
        if (n >= 50)
        {
            std::cout << "L";
            n = n - 50;
        }
        if (n >= 40)
        {
            std::cout << "XL";
            n = n - 40;
        }
        if (n >= 10)
        {
            std::cout << "X";
            n = n - 10;
        }
        if (n >= 10)
        {
            std::cout << "X";
            n = n - 10;
        }
        if (n >= 10)
        {
            std::cout << "X";
            n = n - 10;
        }
        if (n >= 9)
        {
            std::cout << "IX";
            n = n - 40;
        }
        if (n >= 5)
        {
            std::cout << "V";
            n = n - 5;
        }
        if (n >= 4)
        {
            std::cout << "IV";
            n = n - 4;
        }
        if (n >= 1)
        {
            std::cout << "I";
            n = n - 1;
        }
        if (n >= 1)
        {
            std::cout << "I";
            n = n - 1;
        }
        if (n >= 1)
        {
            std::cout << "I";
            n = n - 1;
        }
    }
    return 0;
}