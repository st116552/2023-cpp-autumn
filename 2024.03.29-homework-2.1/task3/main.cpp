#include <iostream>
 
int main() {
    int n = 0;
    int tmp = 0;
    std::cin >> n;
    int** matrix = new int*[n];
    int* colors = new int[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        std::cin >> colors[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1 && colors[i] != colors[j]) {
                tmp++;
            }
        }
    }
    std::cout << tmp;
    return 0;
}