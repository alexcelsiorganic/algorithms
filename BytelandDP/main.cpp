#include <iostream>
#include <vector>
#include <fstream>


int byte_land(std::vector<int> &stations, int m) {
    int size = stations.size();
    int*** matrix = new int**[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int*[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = new int[m + 1];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int m_ = 0; m_ < m + 1; m_++) {
                if (i <= j && m_ == 0) {
                    int sum = 0;
                    if (i == j) {
                        matrix[i][j][m_] = sum;
                    }
                    else {
                        for (int i_1 = i; i_1 < j; i_1++) {
                            for (int j_1 = i_1 + 1; j_1 < j + 1; j_1++) {
                                sum += stations[i_1] * stations[j_1];
                            }
                        }
                        matrix[i][j][m_] = sum;
                    }
                } else {
                    matrix[i][j][m_] = 0;
                }
            }
        }
    }
    int m_ = 1;
    while (m_ < m + 1) {
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (j - i == 1 || j - i == 0) {
                    matrix[i][j][m_] = 0;
                } else {
                    int k = i;
                    int key = INT_MAX;
                    while (k < j) {
                        int temp = matrix[i][k][0] + matrix[k + 1][j][m_ - 1];
                        if (temp < key) {
                            key = temp;
                        }
                        if (temp > key) {
                            break;
                        }
                        k += 1;
                    }
                    matrix[i][j][m_] = key;
                }
            }
        }
        m_ += 1;
    }
    return matrix[0][size - 1][m];
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    int m = 0;
    input >> n;
    input >> m;
    std::vector<int> stations;
    int el = 0;
    for (int i = 0; i < n; i++) {
        input >> el;
        stations.push_back(el);
    }
    output << byte_land(stations, m);
    return 0;
}
