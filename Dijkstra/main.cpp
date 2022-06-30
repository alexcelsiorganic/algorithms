#include <iostream>
#include <fstream>
#include <queue>
#include <set>
using namespace std;


int Dijkstra(std::vector <std::vector<std::pair<int, int>>> g, int start, int n) {
    std::vector<long long> dist(n, LLONG_MAX);
    set<std::pair<int, long long>> q;
    dist[start] = 0;
    std::pair<int, long long> st;
    st.first = 0;
    st.second = start;
    q.insert(st);
    while (!q.empty()) {
        int a1 = q.begin()->second;
        int a2 = q.begin()->first;
        q.erase(q.begin());
        for (auto i : g[a2]) {
            int to = i.first;
            int weight = i.second;
            if (dist[a2] + weight < dist[to]) {
                std::pair<int, long long> del_ins;
                del_ins.first = to;
                del_ins.second = dist[to];
                q.erase(del_ins);
                dist[to] = dist[a2] + weight;
                q.insert(del_ins);
            }
        }
    }
    return dist[n - 1];
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    int m = 0;
    input >> m;
    std::vector<std::vector<std::pair<int, int>>> list(n);
    int start = 0;
    for (int i = 0; i < m;   i++) {
        int a1 = 0;
        std::pair<int, int> v;
        int a2 = 0;
        long long a3 = 0;
        input >> a1;
        start = a1;
        input >> a2;
        input >> a3;
        v.first = a2 - 1;
        v.second = a3;
        list[a1 - 1].push_back(v);
        list[a2 - 1].push_back(v);
    }
    output << Dijkstra(list, 0, n);
}