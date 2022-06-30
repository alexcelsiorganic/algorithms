#include <iostream>
#include <fstream>

int dp(int** matrix, int n, int m) {
    int sum = -1;
    int **paths = new int*[n];
    for (int i = 0; i < n; i++) {
        paths[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            paths[i][j] = INT_MAX;
        }
    }
    paths[0][0] = matrix[0][0];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (paths[i + 1][j] > matrix[i + 1][j] + paths[i][j] && paths[i][j] !=INT_MAX ) {
                paths[i + 1][j] = matrix[i + 1][j] + paths[i][j];
            }
            if (j + 1 < m && paths[i + 1][j + 1] > matrix[i + 1][j + 1] + paths[i][j] && paths[i][j] != INT_MAX) {
                paths[i + 1][j + 1] = matrix[i + 1][j + 1] + paths[i][j];
            }
            if (j - 1 >= 0 && paths[i + 1][j - 1] > matrix[i + 1][j - 1] + paths[i][j] && paths[i][j] != INT_MAX) {
                paths[i + 1][j - 1] = matrix[i + 1][j - 1] + paths[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << paths[i][j] << " ";
        }
        std::cout << std::endl;
    }
    if (paths[n - 1][m - 1] == INT_MAX) {
        return -1;
    }
    else {
        return paths[n - 1][m - 1];
    }
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    int m = 0;
    input >> n;
    input >> m;
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            input >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    output << dp(matrix, n, m);
    return 0;
}
