#include <iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
    int n = 0;
    int max = 0;
    std::cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> *(arr + i);
    }
    max = *(arr);
    for (int i = 0; i < n; i++) 
    {        
        if (max < *(arr + i))
        {
            max = *(arr + i);
        }
    }
	free(arr);
    std::cout << max;
    return 0;
}