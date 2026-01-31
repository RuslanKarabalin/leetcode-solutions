#include <climits>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        const auto& x = v[i];
        out << x;
        if (i < v.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

class Solution {
   public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();

        while (i < n && s[i] == ' ') {
            ++i;
        }

        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            ++i;
        }

        int result = 0;
        while (i < n && '0' <= s[i] && s[i] <= '9') {
            int digit = (int)s[i] - '0';

            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > 7)) {
                if (sign == 1) {
                    return INT_MAX;
                }
                return INT_MIN;
            }

            result = result * 10 + digit;
            ++i;
        }

        return sign * result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << s.myAtoi(" -042") << std::endl;

    return 0;
}
