#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int tmp = 1;
    for (int i = 1; i < n + 1; i++) 
    {
        if (tmp * (tmp + 1) / 2 < i) 
        {
            tmp++;
        }
        std::cout << tmp << " ";
    }
    return 0;
}