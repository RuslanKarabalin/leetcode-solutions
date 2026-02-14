#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int majorityElement(std::vector<int>& nums) {
        int n = nums.size() / 2;
        std::unordered_map<int, int> map;

        for (int num : nums) {
            int count = ++map[num];
            if (count > n) {
                return num;
            }
        }

        return -1;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> v1 = {3, 2, 3};
    std::cout << s.majorityElement(v1) << std::endl;

    std::vector<int> v2 = {2, 2, 1, 1, 1, 2, 2};
    std::cout << s.majorityElement(v2) << std::endl;

    return 0;
}
