#include <iostream>

using namespace std;

class Solution {
    bool isPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return true;
        }
        if (n == 1) {
            return true;
        }

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

   public:
    bool validPalindrome(string s) {
        int n = s.length();
        if (n == 0 || n == 1) {
            return true;
        }
        if (n == 2) {
            return true;
        }

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
            } else {
                string lsub = s.substr(l, r - l);
                string rsub = s.substr(l + 1, r - l);
                if (!isPalindrome(lsub) && !isPalindrome(rsub)) {
                    return false;
                } else {
                    return true;
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
    bool res = s.validPalindrome("abccbva");
    cout << res << "\n";

    return 0;
}
