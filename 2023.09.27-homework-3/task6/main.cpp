#include <iostream>

int main()
{
    int n = 0;
    int ans = 0;
    std::cin >> n;
    int prev0 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++) 
    {
        ans = prev0 + prev1;
        prev0 = prev1;
        prev1 = ans;
    }
    if (n == 0)
    {
        ans = 0;
    }
    if (n == 1)
    {
        ans = 1;
    }
    std::cout << ans;
    return 0;
}