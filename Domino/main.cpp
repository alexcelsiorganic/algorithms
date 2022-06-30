#include <iostream>
#include <fstream>
#include <queue>
#include <stack>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    if (n <= 1) {
        output << "No";
        return 0;
    }
    std::vector<std::vector<int>> list;
    for (int i = 0; i < 7; i++) {
        std::vector<int> a;
        list.push_back(a);
    }
    int start = 0;
    for (int i = 0; i < n; i++) {
        int a1 = 0;
        int a2 = 0;
        input >> a1;
        start = a1;
        input >> a2;
        list[a1].push_back(a2);
        list[a2].push_back(a1);
    }
    std::queue<int> q;
    q.push (start);
    if (n <= 7) {
        n = 7;
    }
    std::vector<int> used(n);
    std::vector<int> d(n);
    used[start] = true;
    for (int i = 0; i < 7; i++) {
        if (list[i].size() != 0) {
            d[i] = -100;
        }
        else {
            d[i] = 0;
        }
    }
    d[start] = 0;
    while (!q.empty()) {
        int vr = q.front();
        q.pop();
        for (int i = 0; i < list[vr].size(); i++) {
            int v_ = list[vr][i];
            if (!used[v_]) {
                used[v_] = true;
                q.push(v_);
                d[v_] = d[vr] + 1;
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        std::cout << d[i] << ' ';
//    }
    bool check = true;
    for (int i = 0; i < n; i++) {
        if (d[i] == -100) {
            check = false;
            break;
        }
    }
    if (!check) {
        output << "No";
    }
    else {
        for (int i = 0; i < n; i++) {
            if (list[i].size() % 2 != 0) {
                check = false;
                break;
            }
    //            if (list[i].size() % 2 == 0 && used[i] == false) {
    //                check = false;
    //                break;
    //            }
        }
        if (!check) {
            output << "No";
        }
        else {
            output << "Yes";
        }
    }
}
