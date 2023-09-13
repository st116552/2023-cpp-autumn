#include <iostream>

int main() 
{
    long long a = 0;
    long long ans = 0;;
    std::cin >> a;
    long long tmp = a / 10;
    ans = (tmp) * (tmp + 1) * 100 + 25;
    std::cout << ans;
    return 0;
}