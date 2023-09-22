#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    if (a == 0 && b == 0)
    {
        std::cout << "INF";
    }
    else if (a == 0 && b != 0)
    {
        std::cout << "NO";
    }
    else if (c == 0 && d == 0)
    {
        std::cout << "NO";
    }
    else if (a * d == b * c)
    {
        std::cout << "NO";
    }
    else 
    {
        if (b % a == 0) 
        {
            std::cout << (0 - b) / a;
        } 
        else
        {
            std::cout << "NO";
        }
    }
    return 0;
}