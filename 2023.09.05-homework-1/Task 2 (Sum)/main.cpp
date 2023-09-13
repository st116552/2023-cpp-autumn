#include <iostream>
#include <stdlib.h>

int main() 
{
    int n = 0;
    int sum = 0;
    std::cin >> n;
    sum = (n + 1) * (abs(n - 1) + 1) / 2;
    std::cout << sum;
    return 0;
}