#include <iostream>
#include <string>

class Solution {
   public:
    std::string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            std::string result = rle("1");
            int i = 1;
            while (i < n - 1) {
                result = rle(result);
                ++i;
            }
            return result;
        }
    }

   private:
    std::string rle(const std::string& nStr) {
        char num = nStr[0];
        int countOfNum = 1;
        std::string result;
        for (int i = 1; i < nStr.length(); ++i) {
            if (num == nStr[i]) {
                ++countOfNum;
            } else {
                result += std::to_string(countOfNum);
                result += num;
                num = nStr[i];
                countOfNum = 1;
            }
        }
        result += std::to_string(countOfNum);
        result += num;
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.countAndSay(4) << std::endl;

    return 0;
}
