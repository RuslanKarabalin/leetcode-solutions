#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool checkChar(char c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') ||
               ('0' <= c && c <= '9');
    }

   public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        vector<char> chars;
        for (char c : s) {
            if (checkChar(c)) {
                if (c <= 'Z') {
                    c += 'a' - 'Z' + 25;
                }
                chars.push_back(c);
            }
        }

        // for (char c : chars) {
        //     cout << c;
        // }
        // cout << std::endl;

        int l = 0;
        int r = chars.size() - 1;
        while (l < r) {
            char lc = chars[l];
            char rc = chars[r];
            // cout << "lc: " << lc << ", rc: " << rc << std::endl;
            if (lc != rc) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    cout << s.isPalindrome("Zeus was deified, saw Suez.") << std::endl;

    return 0;
}
