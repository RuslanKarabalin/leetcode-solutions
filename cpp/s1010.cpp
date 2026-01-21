#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();

        unordered_map<int, int> tmod_to_count;
        for (int t : time) {
            int v = t % 60;
            unordered_map<int, int>::iterator it = tmod_to_count.find(v);
            if (it == tmod_to_count.end()) {
                tmod_to_count[v] = 1;
            } else {
                (it->second)++;
            }
        }

        long long res = 0;
        for (pair<int, int> p : tmod_to_count) {
            int rem = (60 - p.first) % 60;
            unordered_map<int, int>::iterator it = tmod_to_count.find(rem);
            if (it != tmod_to_count.end()) {
                if (p.first == 0 || p.first == 30) {
                    res += ((long long)p.second * (p.second - 1)) / 2;
                } else {
                    res += p.second * it->second;
                }
                it->second = 0;
            }
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<int> in0 = {30, 20, 150, 100, 40};

    cout << s.numPairsDivisibleBy60(in0) << "\n";

    return 0;
}
