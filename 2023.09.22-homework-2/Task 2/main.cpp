#include <iostream>

int main()
{
    int testAns = 0;
    int kidAns = 0;
    std::cin >> testAns;
    std::cin >> kidAns;
    if (testAns == 1 && kidAns == 1) 
    {
        std::cout << "YES";
    }
    else if (testAns != 1 && kidAns != 1)
    {
        std::cout << "YES";
    }
    else if (testAns == 1 && kidAns != 1)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "NO";
    }
 
}