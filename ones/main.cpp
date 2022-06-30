#include <iostream>


long long pow(long long base, long long p) {
    if (p == 1) {
        return base;
    }
    if (p % 2 == 0) {
        long long t = pow(base, p / 2);
        return t * t % 1000000007;
    }
    else {
        return pow(base, p - 1) * base % 1000000007;
    }
}

long long ones(int n, int k) {
    long long answer_1 = 1;
    long long answer_2 = 1;
    long long answer_3 = 1;
    int n_ = n;
    while (n_ != 0) {
        answer_1 = (answer_1 % 1000000007 * n_ % 1000000007) % 1000000007;
        n_ -= 1;
    }
    int k_ = k;
    while (k_ != 0) {
        answer_2 = (answer_2 % 1000000007 * k_ % 1000000007) % 1000000007;
        k_ -= 1;
    }
    int n_k = n - k;
    while (n_k != 0) {
        answer_3 = (answer_3 % 1000000007 * n_k % 1000000007) % 1000000007;
        n_k -= 1;
    }
    return (answer_1 * pow(answer_2 * answer_3 % 1000000007,1000000007 - 2) % 1000000007);
}


int main() {
    int N = 0;
    int k = 0;
    std::cin >> N;
    std::cin >> k;
    std::cout << ones(N, k);
    return 0;
}
