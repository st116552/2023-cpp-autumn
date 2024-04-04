#include <iostream>
  
int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    std::cin >> n >> a >> b;
    int* prev = new int[n];
    prev[0] = 0;
    for (int i = 1; i < n; i++) 
    {
        std::cin >> prev[i];
    }
    while (a != b)
    {
        if (a > b)
        {
            a = prev[a - 1];
        }
        else
        {
            b = prev[b - 1];
        }
        
    }
    std::cout << a;
    return 0;
}