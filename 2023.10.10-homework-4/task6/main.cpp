#include <iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
    int n = 0;
    int lastMaxNum = 0;
    int firstMinNum = 0;
    int tmp = 0;
    std::cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> *(arr + i);
    }
    for (int i = 0; i < n; i++) 
    {        
        if (*(arr + lastMaxNum) <= *(arr + i))
        {
            lastMaxNum = i;
        }
        if (*(arr + firstMinNum) > *(arr + i))
        {
            firstMinNum = i;
        }
    }
    tmp = *(arr + lastMaxNum);
    *(arr + lastMaxNum) = *(arr + firstMinNum);
    *(arr + firstMinNum) = tmp;
    for (int i = 0; i < n; i++) 
    {        
        std::cout << *(arr + i) << " ";
    }
	free(arr);
    return 0;
}