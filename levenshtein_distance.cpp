#include <algorithm>
#include <vector>
#include <cstddef>
#include <iostream>
#include <string>

int get_levenshtein_distance(const std::string& str1, const std::string& str2) {
    std::vector<std::vector<int>> d (str1.size() + 1, std::vector<int> (str2.size() + 1));
    for (int i = 0; i < str1.size() + 1; ++i) {
        d[i][0] = i;
    }
    for (int j = 0; j < str2.size() + 1; ++j) {
        d[0][j] = j;
    }
    for (int i = 1; i < str1.size() + 1; ++i) {
        for (int j = 1; j < str2.size() + 1; ++j) {
            int c = 0;
            str1[i - 1] == str2[j - 1] ? c = 0 : c = 1;
            int smallest = std::min(d[i - 1][j] + 1, d[i][j - 1] + 1);
            d[i][j] = std::min(smallest, d[i - 1][j - 1] + c);
        }
    }
    return d[str1.size()][str2.size()];
}

int main(void) {
    std::string str1;
    std::string str2;

    std::cin >> str1 >> str2;

    std::cout << get_levenshtein_distance(str1, str2) << std::endl;
}