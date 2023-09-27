#include <iostream>

int main()
{
    int n = 0;
    int ans = 0;
    std::cin >> n;
    for (int i = 0; (i + 1) * (i + 1) <= n; i++) 
    {
        if (n % (i + 1) == 0)
        {
            ans = ans + 2;
        }
        if ((i + 1) * (i + 1) == n)
        {
            ans = ans - 1;
        }
    }
   
    std::cout << ans;
    return 0;
}