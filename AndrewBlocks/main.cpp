#include <iostream>



int dp(long long *as, long long* bs, int n) {
    long long** matrix = new long long*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new long long[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int j = 1; j < n; j++) {
        for (int i = j - 1; i >= 0; i--) {
            long long min = LLONG_MAX;
           for (int k = i; k < j; k++) {
               if (min > matrix[i][k] + matrix[k + 1][j] + as[i] * bs[j]) {
                   min = matrix[i][k] + matrix[k + 1][j] + as[i] * bs[j];
               }
           }
           matrix[i][j] = min;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<matrix[0][n - 1];
    return 0;
}



int main() {
    int n;
    std::cin >> n;
    long long* as = new long long[n];
    long long* bs = new long long[n];
    for (int i = 0; i < n; i++) {
        std::cin >> as[i];
        std::cin >> bs[i];
    }
    dp(as, bs, n);
    return 0;
}
