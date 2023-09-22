#include <iostream>

int findNumOfPassAndSubstract(int passType, int *num)
{
    int ans = *num / passType;
    *num = *num % passType;
    return ans;
}

int main()
{
    int n = 0;
    std::cin >> n;
    int n60 = findNumOfPassAndSubstract(60, &n);
    int n20 = findNumOfPassAndSubstract(20, &n);
    int n10 = findNumOfPassAndSubstract(10, &n);
    int n5 = findNumOfPassAndSubstract(5, &n);
    int n1 = findNumOfPassAndSubstract(1, &n);
    if (n1 * 15 >= 70) 
    {
        n5++;
        n1 = 0;
    }
    if (n5 * 70 + n1 * 15 >= 125) 
    {
        n10++;
        n1 = 0;
        n5 = 0;
    }
    if (n10 * 125 + n5 * 70 + n1 * 15 >= 230) 
    {
        n20++;
        n1 = 0;
        n5 = 0;
        n10 = 0;
    }
    if (n20 * 230 + n10 * 125 + n5 * 70 + n1 * 15 >= 440) 
    {
        n60++;
        n1 = 0;
        n5 = 0;
        n10 = 0;
        n20 = 0;
    }
    std::cout << n1 << " ";
    std::cout << n5 << " ";
    std::cout << n10 << " ";
    std::cout << n20 << " ";
    std::cout << n60 << " ";
    return 0;
}