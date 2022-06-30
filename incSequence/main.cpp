#include <iostream>
#include <fstream>


int mostLong(const int **a, int n, int m) {
    int* array = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        array[i] = 1000000001;
    }
    array[0] = -1000000001;
    for (int i = 0; i < n; i++) {
        int max = 0;
        int key = a[i];
        int l = 0;
        int r = n;
        int m = 0;
        while (l < r) {
            m = (l + r) / 2;
            if (array[m] < key) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        array[r] = a[i];
    }
    int max = 0;
    for (int i = 0; i < n + 1; i++) {
        if (array[i] != 1000000001) {
            max = i;
        }
    }
    return max;
}


int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int n;
    int m;
    fin >> n;
    fin >> m;
    int** paralls = new int*[m];
    for (int i = 0; i < m; i++) {
        paralls[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> paralls[i][j];
        }
    }
    fout << mostLong(paralls, n, m);
    for (int i = 0; i < m; i++) {
       delete[] paralls[i];
    }
    delete[] paralls;
    return 0;
}
