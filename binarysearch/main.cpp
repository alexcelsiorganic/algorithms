#include <iostream>
#include <fstream>

bool binarySearch(long long* a, long long b, int size1) {
    int l = 0;
    int r = size1;
    int m = 0;
    while (l < r) {
        m = (l + r) / 2;
        if (a[m] == b) {
            return true;
        } else if (a[m] < b) {
            l = m + 1;
        } else if (a[m] > b) {
            r = m;
        }
    }
    return false;
}


int first_greater_equal(long long* a, long long b, int size1) {
    int l = 0;
    int r = size1;
    int m = 0;
    while (l < r) {
        m = (l + r) / 2;
        if (b <= a[m]) {
           r = m;
        }
        else {
           l = m + 1;
        }
    }
    return l;
}


int first_greater(long long* a, long long b, int size1) {
    int l = 0;
    int r = size1;
    int m = 0;
    while (l < r) {
        m = (l + r) / 2;
        if (a[m] <= b) {
            l = m + 1;
        }
        else {
           r = m;
        }
    }
    return l;
}


int main() {
    int n = 0;
    std::cin >> n;
    auto* vec = new long long [n];
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    int requests_size = 0;
    std::cin >> requests_size;
    auto* req = new long long [requests_size];
    for (long long i = 0; i < requests_size; i++) {
        std::cin >> req[i];
    }
    for (int i = 0; i < requests_size; i++) {
        int index1 = first_greater_equal(vec, req[i], n);
        int index2 = first_greater(vec, req[i], n);
        if (i == requests_size - 1) {
            if (binarySearch(vec, req[i], n)) {
                std::cout << "1" << " " << index1 << " " << index2;
            } else {
                std::cout << "0" << " " << index1 << " " << index2;
            }
        }
        else {
            if (binarySearch(vec, req[i], n)) {
                std::cout << "1" << " " << index1 << " " << index2 << std::endl;
            } else {
                std::cout << "0" << " " << index1 << " " << index2 << std::endl;
            }
        }
    }
    return 0;
}
