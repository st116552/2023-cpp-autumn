#include <iostream>

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n;
    std::cin >> m;
    int* lights = new int[n];
    for (int i = 0; i < n; i++) {
        lights[i] = 0;
    }
    int tmp = 0;
    for (int i = 0; i < 2 * m; i++) {
        std::cin >> tmp;
        lights[tmp - 1]++;
    }
    for (int i = 0; i < n; i++) {
        std::cout << lights[i] << " ";
    }
    return 0;
}