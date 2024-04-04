#include <iostream>
 
int main() {
    int n = 0;
    long long a1 = 0;
    long long a2 = 0;
    std::cin >> n >> a1 >> a2;
    while (a1 != a2) {
        if (a1 > a2) {
            a1 = a1 / 2;
        } else {
            a2 = a2 / 2;
        }
    }
    std::cout << a1;
    return 0;
}