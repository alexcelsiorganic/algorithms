#include <iostream>
#include <fstream>
#include <vector>


void build(int* &cities, int m, int n,
           int* requests, std::pair<int, int>* roads, int q,
           int* check, std::ofstream& output) {
    int count = n;
    for (int i = 0; i < m; i++) {
        if (check[i] == 0) {
            int parent_city_1 = roads[i].first;
            while (cities[parent_city_1] > 0) {
                parent_city_1 = cities[parent_city_1];
            }
            int parent_city_2 = roads[i].second;
            while (cities[parent_city_2] > 0) {
                parent_city_2 = cities[parent_city_2];
            }
            if (parent_city_1 != parent_city_2) {
                if (cities[parent_city_1] * -1 < cities[parent_city_2] * -1) {
                    cities[parent_city_2] += cities[parent_city_1];
                    cities[parent_city_1] = roads[i].second;
                    count -= 1;
                } else {
                    cities[parent_city_1] += cities[parent_city_2];
                    cities[parent_city_2] = roads[i].first;
                    count -= 1;
                }
            }
        }
    }
    if (q != 0) {
        int *answer = new int[q];
        for (int i = 0; i < q; i++) {
            answer[i] = 1;
        }
        for (int i = q - 1; i >= 0; i--) {
            if (count > 1) {
                int parent_city_1 = roads[requests[i]].first;
                while (cities[parent_city_1] > 0) {
                    parent_city_1 = cities[parent_city_1];
                }
                int parent_city_2 = roads[requests[i]].second;
                while (cities[parent_city_2] > 0) {
                    parent_city_2 = cities[parent_city_2];
                }
                if (parent_city_1 != parent_city_2) {
                    if (cities[parent_city_1] * -1 < cities[parent_city_2] * -1) {
                        cities[parent_city_2] += cities[parent_city_1];
                        cities[parent_city_1] = roads[requests[i]].second;
                        count -= 1;
                    } else {
                        cities[parent_city_1] += cities[parent_city_2];
                        cities[parent_city_2] = roads[requests[i]].first;
                        count -= 1;
                    }
                }
                answer[i] = 0;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < q; i++) {
            output << answer[i];
        }
    }
    output.close();
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    int m = 0;
    input >> m;
    int q = 0;
    input >> q;
    int* cities = new int[n + 1];
    auto* roads = new std::pair<int, int>[m];
    int* check = new int[m];
    int* requests = new int[q];
    for (int i = 1; i < n + 1; i++) {
        cities[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        std::pair<int, int> road;
        input >> road.first;
        input >> road.second;
        roads[i] = road;
        check[i] = 0;
    }
    for (int i = 0; i < q; i++) {
        int x = 0;
        input >> x;
        requests[i] = x - 1;
        check[x - 1] = 1;
    }
    build(cities, m, n, requests, roads, q, check, output);
    delete[] roads;
    delete[] cities;
    delete[] check;
    delete[] requests;
    return 0;
}
