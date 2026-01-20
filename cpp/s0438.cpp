#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();

        vector<int> result;
        if (pLen > sLen) {
            return result;
        }

        unordered_map<char, int> c_to_count;
        for (char c : p) {
            unordered_map<char, int>::iterator it = c_to_count.find(c);
            if (it == c_to_count.end()) {
                c_to_count[c] = 1;
            } else {
                (it->second)++;
            }
        }

        unordered_map<char, int> map;
        int inMap = 0;
        for (int i = 0; i < sLen + 1; ++i) {
            char c = s[i];
            if (inMap >= pLen) {
                if (map == c_to_count) {
                    result.push_back(i - pLen);
                }
                char pc = s[i - pLen];
                unordered_map<char, int>::iterator pci = map.find(pc);
                if (pci->second == 1) {
                    map.erase(pc);
                } else {
                    --(pci->second);
                }
                --inMap;
            }
            unordered_map<char, int>::iterator it = map.find(c);
            if (it == map.end()) {
                map[c] = 1;
            } else {
                ++(it->second);
            }
            ++inMap;
        }

        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<int> res = s.findAnagrams("cbaebabacd", "abc");

    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
