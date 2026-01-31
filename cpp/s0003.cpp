#include <iostream>
#include <set>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int maxLen = 0;

        set<char> chars;
        for (int i = 0; i < n; ++i) {
            chars.clear();
            for (int j = i; j < n; ++j) {
                set<char>::iterator i = chars.find(s[j]);
                if (i != chars.end()) {
                    break;
                }
                chars.insert(s[j]);
                if (chars.size() > maxLen) {
                    maxLen = chars.size();
                }
            }
        }

        return maxLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    cout << s.lengthOfLongestSubstring(
                "zkrassqjwvonakhdnbpkmolkbwqztcbumuugonqlieaipjoekdoxrbhszzrsdu"
                "prqjyfyosgssrjcfnmidlbettduny")
         << std::endl;

    return 0;
}
