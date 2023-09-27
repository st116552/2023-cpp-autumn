#include <iostream>

int main()
{
    int n = 0;
    int ans = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        tmp1 = i;
        tmp2 = 0;
        while (tmp1 > 0) 
        {
            tmp2 = tmp2 * 10 + tmp1 % 10;
            tmp1 = tmp1 / 10;
        }
        if (i == tmp2) 
        {
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}