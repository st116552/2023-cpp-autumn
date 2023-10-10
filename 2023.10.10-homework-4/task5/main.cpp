#include <iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> *(arr + i);
    }
    for (int i = n - 1; i >= 0; i--) 
    {        
        std::cout << *(arr + i) << " ";
    }
    free(arr);
    return 0;
}