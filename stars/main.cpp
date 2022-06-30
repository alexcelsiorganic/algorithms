#include <iostream>
#include <fstream>

const int N = 524288;
int segment_tree[2 * N];


void add_up(int x){
    for (int i = N + x; i >= 1; i >>= 1) {
        segment_tree[i] += 1;
    }
}


int find_sum(int l, int r) {
    l += N;
    r += N;
    int ans = 0;
    while (l < r) {
        if (l & 1) {
            ans += segment_tree[l++];
        }
        if (r & 1) {
            ans += segment_tree[--r];
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int num_of_stars = 0;
    input >> num_of_stars;


    int *levels = new int[num_of_stars];
    for(int i = 0; i < num_of_stars; i++) {
        levels[i] = 0;
    }
    levels[0] = 1;


    int x;
    int y;
    input >> x;
    add_up(x);
    input >> y;
    int min_x = x + 1;
    int level = 1;
    int current_y = y;


    for (int i = 1; i < num_of_stars; i++) {
        input >> x;
        input >> y;
        if (y > current_y) {
            current_y = y;
            min_x = 0;
            level = 0;
        }
        level += find_sum(min_x, x + 1);
        add_up(x);
        min_x = x + 1;
        levels[level] += 1;
        level += 1;
    }


    for (int i = 0; i < num_of_stars; i++) {
        if (i != num_of_stars - 1) {
            output << levels[i] << std::endl;
        }
        else {
            output << levels[i];
        }
    }
    return 0;
}
