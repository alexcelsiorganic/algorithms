#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

//void DFS(int** matrix, int* &marks, int n, int vert, bool * visited) {
//    int mark = 1;
//    std::stack<int> vertex;
//    visited[vert] = true;
//    vertex.push(vert);
//    marks[vert] = mark;
//    while (!vertex.empty() || mark < n + 1) {
//        if (vertex.empty()) {
//            for (int i = 0; i < n; i++) {
//                if (!visited[i]) {
//                    visited[i] = true;
//                    vertex.push(i);
//                }
//            }
//        }
//        else {
//            int a = vertex.top();
//            marks[a] = mark;
//            mark += 1;
//            vertex.pop();
//            for (int i = n - 1; i >= 0; i--) {
//                if (matrix[a][i] == 1 && !visited[i]) {
//                    visited[i] = true;
//                    vertex.push(i);
//                }
//            }
//        }
//    }
//}

void DFS(int** matrix, int* &marks, int n, int vert, bool * visited,  int& mark) {
    if (!visited[vert]) {
        visited[vert] = true;
        marks[vert] = mark;
        mark += 1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && matrix[vert][i] == 1) {
                DFS(matrix, marks, n, i, visited, mark);
            }
        }
    }
}

void RunDFS(int** matrix, int* &marks, int n, bool * visited,  int& mark) {
    for (int i = 0; i < n; i++) {
        DFS(matrix, marks, n, i, visited, mark);
    }
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> matrix[i][j];
        }
    }
    bool* visited = new bool[n];

    int* m = new int[n];
    for (int i = 0; i < n; i++) {
        m[i] = 0;
        visited[i] = false;
    }
    int mark = 1;
    RunDFS(matrix, m, n, visited,  mark);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            output << m[i];
        }
        else {
            output << m[i] << " ";
        }
    }
}