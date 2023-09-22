#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    if (a <= b && a <= c) 
    {
        std::cout << a << " ";
        if (b <= c) 
        {   
        std::cout << b << " " << c;
        }
        else
        {
        std::cout << c << " " << b;
        }
    }
    else if (b <= a && b <= c)
    {
        std::cout << b << " ";
        if (a <= c) 
        {   
        std::cout << a << " " << c;
        }
        else
        {
        std::cout << c << " " << a;
        }
    }
    else
    {
        std::cout << c << " ";
        if (a <= b) 
        {   
        std::cout << a << " " << b;
        }
        else
        {
        std::cout << b << " " << a;
        }
    }
    return 0;
}