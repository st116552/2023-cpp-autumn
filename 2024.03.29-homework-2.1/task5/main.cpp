#include <iostream>
 
int main() {
    int n = 0;
    int a1 = 0;
    int a2 = 0;
    std::cin >> n >> a1 >> a2;
    // for (int i = 0; i < n && a1 != a2; i++) {
    //     a1 = a1 / 2;
    //     a2 = a2 / 2;
    // }
    while (a1 != a2) {
        if (a1 > a2) {
            a1 = a1 / 2;
        } else {
            a2 = a2 / 2;
        }
    }
    std::cout << a2;
    return 0;
}