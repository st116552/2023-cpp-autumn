#include <iostream>

int main()
{
    int time = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    std::cin >> k;
    std::cin >> m;
    std::cin >> n;
    if (n > k && 2 * n % k == 0)
    {
        time = 2 * n  * m / k;
    }
    else if (n > k && 2 * n % k != 0) 
    {
        time = (2 * n / k + 1) * m;
    }
    else 
    {
        time = 2 * m;
    }
    std::cout << time;
    return 0;
}