#include <iostream>

int main() 
{
    int n = 0;
    std::cin >> n;
    if (n % 10 == 1 && n / 10 % 10 != 1) 
    {
        std::cout << n << " bochka";
    }
    else if ((n % 10 == 2 || n % 10 == 3 || n % 10 == 4) && n / 10 % 10 != 1)
    {
        std::cout << n << " bochki";
    }
    else
    {
        std::cout << n << " bochek";
    }
    return 0;
}