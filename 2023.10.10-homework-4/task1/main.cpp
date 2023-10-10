#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    int n = 0;
    int positiveNum = 0;
    std::cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> *(arr + i);
    }
    for (int i = 0; i < n; i++) 
    {
        if (*(arr + i) > 0)
        {
            positiveNum++;
        }
    }
    free(arr);
    std::cout << positiveNum;
    return 0;
}