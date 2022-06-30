#include <iostream>
#include <fstream>
#include <queue>
#include <math.h>


using namespace std;

bool kun_algorithm(int v, vector<bool> &used, vector<vector<int>> &graph, vector<int> &pairs) {
    if (used[v])  {
        return false;
    }
    used[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
        int v0 = graph[v][i];
        if (pairs[v0] == -1 || kun_algorithm(pairs[v0], used, graph, pairs)) {
            pairs[v0] = v;
            return true;
        }
    }
    return false;
}

double min(double a, double b) {
    if (a <= b) {
        return a;
    }
    return b;
}

bool necessary_condition(double a1, double a2, double b1, double b2) {
    if (a1 * a2 <= b1 * b2 && a1 * a1 + a2 * a2 <= b1 * b1 + b2 * b2) {
        if (a1 + a2 <= b1 + b2 && min(a1, a2) <= min(b1, b2)) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool compareRectangles(double a1, double a2, double b1, double b2) {
    double max1 = 0;
    double min1 = 0;
    if (a1 <= a2) {
        max1 = a2;
        min1 = a1;
    }
    else {
        max1 = a1;
        min1 = a2;
    }
    double max2 = 0;
    double min2 = 0;
    if (b1 <= b2) {
        max2 = b2;
        min2 = b1;
    }
    else {
        max2 = b1;
        min2 = b2;
    }
    if (max1 <= max2 && min1 <= min2) {
        return true;
    }
        else if (max1 > max2 && min2 >= (2 * max1 * max2 * min1 + (max1 * max1 - min1 * min1) * sqrt(max1 * max1 + min1 * min1 - max2 * max2)) / (max1 * max1 + min1 * min1)) {
            if (necessary_condition(a1, a2, b1, b2)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
}

int main() {
    std::ifstream input("input.in");
    std::ofstream output("output.out");
    int n = 0;
    input >> n;
    std::vector<pair<double, double>> postcards;
    std::vector<pair<double, double>> envelopes;
    std::vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        double a1 = 0;
        double a2 = 0;
        input >> a1;
        input >> a2;
        pair<double, double> a;
        a.first = a1;
        a.second = a2;
        postcards.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        double a1 = 0;
        double a2 = 0;
        input >> a1;
        input >> a2;
        pair<double, double> a;
        a.first = a1;
        a.second = a2;
        envelopes.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        double a1 = postcards[i].first;
        double a2 = postcards[i].second;
        for (int j = 0; j < n; j++) {
            double b1 = envelopes[j].first;
            double b2 = envelopes[j].second;
            if (compareRectangles(a1, a2, b1, b2)) {
                graph[i].push_back(j);
            }
        }
    }
    vector<int> pairs(n);
    for (int i = 0; i < n; i++) {
        pairs[i] = -1;
    }
    vector<bool> used(n);
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[j] = false;
        }
        if (kun_algorithm(i, used, graph, pairs)) {
            counter += 1;
        }
    }
    if (counter == n) {
        output << "YES";
        return 0;
    }
    else if (counter != n) {
        output << "NO" << std::endl;
        output << counter;
        return 0;
    }

}
