#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int column = 0;
        int row = 0;
        int numColumns = s.length();
        std::vector<std::vector<char>> arr(numRows,
                                           std::vector<char>(numColumns, ' '));
        int i = 0;
        while (i < s.length()) {
            char c = s[i];
            if (column % (numRows - 1) == 0) {
                arr[row][column] = c;
                ++i;
            } else {
                if ((row + column) % (numRows - 1) == 0) {
                    arr[row][column] = c;
                    ++i;
                }
            }

            ++row;
            if (row == numRows) {
                ++column;
                row = 0;
            }
        }

        std::string result;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                char c = arr[i][j];
                if (c != ' ') {
                    result += c;
                }
            }
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << s.convert("PAYPALISHIRING", 4) << std::endl;

    return 0;
}
