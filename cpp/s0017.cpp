#include <iostream>
#include <string>
#include <unordered_map>
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
    std::vector<std::string> mVecs(const std::vector<std::string>& a,
                                   const std::vector<std::string>& b) {
        std::vector<std::string> result;
        result.reserve(a.size() * b.size());

        for (std::string oc : a) {
            for (std::string ic : b) {
                std::string s;
                s.reserve(oc.size() + ic.size());
                s += oc;
                s += ic;
                result.push_back(s);
            }
        }
        return result;
    }

   public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty())
            return {};

        std::unordered_map<char, std::vector<std::string>> m = {
            {'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}}};

        std::vector<std::string> result = m[digits[0]];
        for (size_t i = 1; i < digits.size(); ++i) {
            const auto& c = m[digits[i]];
            result = mVecs(result, c);
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::string in0 = "23";
    std::vector<std::string> re0 = s.letterCombinations(in0);

    for (std::string s : re0) {
        std::cout << s << std::endl;
    }

    return 0;
}
