#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (sLen > tLen) {
            return false;
        }
        if (sLen == tLen) {
            return s == t;
        }

        int si = 0;
        int ti = 0;
        while (si < sLen) {
            if (s[si] == t[ti]) {
                ++si;
                ++ti;
            } else {
                if (ti + 1 < tLen) {
                    ++ti;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    bool res = s.isSubsequence("bb", "ahbgdc");
    cout << res << "\n";

    return 0;
}
