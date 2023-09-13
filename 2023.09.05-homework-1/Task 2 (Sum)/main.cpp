#include <iostream>

int main() 
{
    int n = 0;
    int sum = 0;
    std::cin >> n;
    sum = (n >= 1) * n * (n + 1) / 2 + (n < 1) * (2 - n) * (n + 1) / 2;
    std::cout << sum;
    return 0;
}