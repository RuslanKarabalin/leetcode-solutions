#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> in1 = {1, 2, 3, 1};
    std::cout << s.containsDuplicate(in1) << std::endl;

    std::vector<int> in2 = {1, 2, 3, 4};
    std::cout << s.containsDuplicate(in2) << std::endl;

    return 0;
}
