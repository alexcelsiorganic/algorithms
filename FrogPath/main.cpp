#include <iostream>

void frog_path(const int* a, int n) {
    int *count = new int[n];
    for (int i = 0; i < n; i++) {
        count[i] = -1;
    }
    count[0] = a[0];
    for (int i = 0; i < n; i++) {
        if (i + 2 < n) {
            if (count[i + 2] < count[i] + a[i + 2]) {
                count[i + 2] = count[i] + a[i + 2];
            }
        }
        if (i + 3 < n) {
            if (count[i + 3] < count[i] + a[i + 3]) {
                count[i + 3] = count[i] + a[i + 3];
            }
        }
    }
    int* prev = new int[n];
    for (int i = 0; i < n; i++) {
        prev[i] = 0;
    }
    std::cout << count[n - 1] << std::endl;
    if (count[n - 1] != -1) {
        int counter = n;
        prev[counter - 1] = counter;
        counter -= 1;
        while (counter - 3 >= 0) {
            if (count[counter - 2] >= count[counter - 3]) {
                prev[counter - 2] = counter - 1;
                counter -= 2;
            }
            else if (count[counter - 3] > count[counter - 2]) {
                prev[counter - 3] = counter - 2;
                counter -= 3;
            }
        }
        if (counter - 2 == 0) {
            prev[counter - 2] = counter - 1 ;
        }
        for (int i = 0; i < n; i++) {
            if (prev[i] != 0) {
                std::cout << prev[i] << " ";
            }
        }
    }
    delete[] count;
    delete[] prev;
}


int main() {
    int n;
    std::cin >> n;
    int* mosquits = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mosquits[i];
    }
    frog_path(mosquits, n);
    delete[] mosquits;
    return 0;
}
