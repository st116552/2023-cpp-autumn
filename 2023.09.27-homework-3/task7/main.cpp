#include <iostream>

int main() 
{
    int n = 0;
    std::cin >> n;
    int k = 0;
    int tmp = 1;
    while (tmp < n)
    {
        k++;
        tmp = tmp * 2;
    }
    std::cout << k;
    return 0;
}