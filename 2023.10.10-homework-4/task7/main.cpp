#include <iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
    int n = 0;
    int newSize = 0;
    std::cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> *(arr + i);
        if (*(arr + i) > 0)
        {
            newSize++;
        }
    }
    //copy elements > 0
    int* ansArr = (int*)malloc(sizeof(int) * newSize);
    int j = 0;
    for (int i = 0; i < n; i++) 
    {        
        if (*(arr + i) > 0) 
        {
            *(ansArr + j) = *(arr + i);
            j++;
        }
    }
    //change arr
    free(arr);
    arr = (int*)malloc(sizeof(int) * newSize);
    for (int  i = 0 ; i < newSize; i++)
    {
        *(arr + i) = *(ansArr + i);
    }
    free(ansArr);
    for (int i = 0; i < newSize; i++) 
    {        
        std::cout << *(arr + i) << " ";
    }
    free(arr);
    return 0;
}