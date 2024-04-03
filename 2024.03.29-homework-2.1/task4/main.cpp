#include <iostream>
 
int main() {
    int n = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    int minSum = 10000;
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
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (minSum > matrix[i][j] + matrix[j][k] + matrix[k][i]) {
                    minSum = matrix[i][j] + matrix[j][k] + matrix[k][i];
                    //std::cout << i << " " << j << " " << k << "\n"; 
                }
            }
        }
    }
    std::cout << minSum;
    return 0;
}