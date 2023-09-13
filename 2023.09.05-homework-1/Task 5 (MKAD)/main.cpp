#include <iostream>

using namespace std;

int main() 
{
    int const roadLength = 109;
    long long v = 0;
    long long t = 0;
    long long road = roadLength * 1000000 + 1;
    std::cin >> v >> t;
    road = (road + v * t - 1) % roadLength + 1;
    std::cout << road;
    return 0;
}