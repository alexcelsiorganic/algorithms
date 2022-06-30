#include <iostream>
#include <fstream>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    int m = 0;
    input >> m;
    int* cities = new int[n + 1];
    for (int i = 1; i < n + 1; i++) {
        cities[i] = - 1;
    }
    int answer = n;
    for (int i = 0; i < m; i++) {
        int city_1 = 0;
        int city_2 = 0;
        input >> city_1;
        input >> city_2;
        int parent_city_1 = city_1;
        while (cities[parent_city_1] > 0) {
            parent_city_1 = cities[parent_city_1];
        }
        int parent_city_2 = city_2;
        while (cities[parent_city_2] > 0) {
            parent_city_2 = cities[parent_city_2];
        }
        if (parent_city_1 != parent_city_2) {
            if (cities[parent_city_1] * -1 < cities[parent_city_2] * -1) {
                cities[parent_city_2] += cities[parent_city_1];
                cities[parent_city_1] = city_2;
                answer -= 1;
            } else {
                cities[parent_city_1] += cities[parent_city_2];
                cities[parent_city_2] = city_1;
                answer -= 1;
            }
        }
        if (i != m - 1) {
            output << answer << std::endl;
        }
        else {
            output << answer;
        }
    }
//    for (int j = 1; j < n + 1; j++) {
//        std::cout << cities[j] << " ";
//    }
//    std::cout << std::endl;
    return 0;
}