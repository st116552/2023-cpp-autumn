#include <iostream>

int main() {
    int n = 0;
    int tmp = 0;
    int sumX2 = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> tmp;
            if (tmp == 1) {
                if (i == j) {
                    sumX2 += 2;
                } else {
                sumX2++;
                }
            }
        }
    }
    std::cout << sumX2 / 2;
    return 0;
}