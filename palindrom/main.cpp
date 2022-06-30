#include <iostream>
#include <string>
#include <fstream>

int max(int one, int two) {
    if (one > two) {
        return one;
    } else {
        return two;
    }
}


void palindrom(std::string &str, std::ofstream &out) {
    int **matrix = new int *[str.size()];
    std::string answer;
    for (int i = 0; i < str.size(); i++) {
        matrix[i] = new int[str.size()];
    }
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str.size(); j++) {
            if (i == j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < str.size(); j++) {
        for (int i = j - 1; i >= 0; i--) {
            if (str[i] != str[j]) {
                matrix[i][j] = max(matrix[i][j - 1], matrix[i + 1][j]);
            } else {
                matrix[i][j] = matrix[i + 1][j - 1] + 2;
            }
        }
    }
//    if (matrix[i_][j_ - 1] != matrix[i_ + 1][j_]) {
//        if (matrix[i_][j_ - 1] > matrix[i_ + 1][j_]) {
//            j_ -= 1;
//        } else {
//            i_ += 1;
//        }
//    } else {
//        if (str[i_] == str[j_]) {
//            if (matrix[i_][j_] == matrix[i_ + 1][j_ - 1] + 2) {
//                answer.push_back(str[i_]);
//                i_ += 1;
//                j_ -= 1;
//            } else {
//                answer.push_back(str[j_]);
//                i_ += 1;
//            }
//        } else {
//            i_ += 1;
//        }
    int i_ = 0;
    int j_ = str.size() - 1;
    if (str.size() > 1) {
        while (j_ >= i_) {
            if (i_ != j_ || matrix[i_][j_] != 1) {
                if (str[i_] == str[j_]) {
                    answer.push_back(str[i_]);
                    i_ += 1;
                    j_ -= 1;
                }
                else {
                    if (matrix[i_ + 1][j_] >= matrix[i_][j_ - 1]) {
                        i_ += 1;
                    }
                    else {
                        j_ -= 1;
                    }
                }
            }
            else {
                answer.push_back(str[i_]);
                i_ += 1;
            }
        }
        out << matrix[0][str.size() - 1];
        if (matrix[0][str.size() - 1] % 2 == 0) {
            int ans_size = answer.size();
            int counter = ans_size - 1;
            while (counter >= 0) {
                answer.push_back(answer[counter]);
                counter -= 1;
            }
        } else {
            int ans_size = answer.size();
            int counter = ans_size - 2;
            while (counter >= 0) {
                answer.push_back(answer[counter]);
                counter -= 1;
            }
        }
        out << '\n';
        if (answer.empty()) {
            answer = str[0];
        }
        out << answer;
    } else {
        if (str.size() != 0) {
            out << matrix[0][str.size() - 1];
            out << '\n';
            out << str[0];
        } else {
            out << 0;
        }
    }
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    std::string str;
    in >> str;
    palindrom(str, out);
    return 0;
}
