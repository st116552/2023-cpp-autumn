#include <iostream>

int main()
{
    int n = 0;
    int ans = 0;
    std::cin >> n;
    while (n > 0) 
    {
        ans = ans * 10 + n % 10;
        n = n / 10;
    }
    std::cout << ans;
    return 0;
}