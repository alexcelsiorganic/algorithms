#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int dp(std::vector<int> elements) {
    std::vector<int> mostLong;
    int size = elements.size();
    mostLong.push_back(1);
    for (int i = 0; i < size; i++) {
        mostLong.push_back(-1 * INT_MAX);
    }
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (elements[i] % elements[j] == 0 && mostLong[j] + 1 > mostLong[i]) {
                mostLong[i] = mostLong[j] + 1;
            }
        }
    }
//    for (int i = 0; i < size; i++) {
//        std::cout << mostLong[i] << " ";
//    }
//    std::cout << std::endl;
    int max = -1 * INT_MAX;
    for (int i : mostLong) {
        if (i > max) {
            max = i;
        }
    }
    return max;
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;
    if (n == 0) {
        output << 0;
        output.close();
        input.close();
        return 0;
    }
    int el;
    std::vector<int> elements;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        input >> el;
        if (el < 0) {
            elements.push_back(-1 * el);
        }
        else if (el > 0) {
            elements.push_back(el);
        }
    }
    if (elements.empty()) {
        output << 1;
        output.close();
        input.close();
        return 0;
    }
    int size = elements.size();
    if (size < n) {
        answer += 1;
    }
    std::sort(elements.begin(), elements.end());
//    for (int a = 0; a < array.size(); a++) {
//        std::cout << array[a] << " ";
//    }
    if (elements.size() == 1 && elements.size() < n) {
        answer = 2;
    }
    else {
        answer += dp(elements);
    }
    output << answer;
    input.close();
    output.close();
    return 0;
}
