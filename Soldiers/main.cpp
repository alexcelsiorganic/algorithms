#include <iostream>
#include <fstream>

int dp(int n) {
    int* matrix = new int[n + 1];
    for (int i = 0; i < n; i++) {
        matrix[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = 0;
    }
    matrix[1] = 1;
    matrix[2] = 1;
    matrix[3] = 1;
    for (int i = 4; i < n + 1; i++) {
        if (i % 2 == 1) {
            matrix[i] = matrix[i / 2 + 1] + matrix[i / 2];
            //std::cout << i / 2 + 1 << " " << i / 2 << std::endl;
        }
        else {
            matrix[i] = 2 * matrix[i / 2];
            //std::cout << i / 2 << std::endl;
        }
    }
    for (int i = 0; i < n + 1; i++) {
       std::cout << matrix[i] << " ";
    }
    return matrix[n];
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    output << dp(n);
    return 0;
}
