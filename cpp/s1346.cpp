#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    bool checkIfExist(std::vector<int>& arr) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); ++i) {
            if (map.count(arr[i] * 2) ||
                (arr[i] % 2 == 0 && map.count(arr[i] / 2))) {
                return true;
            }
            map[arr[i]] = i;
        }

        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> a1 = {10, 2, 5, 3};
    std::cout << s.checkIfExist(a1) << std::endl;

    std::vector<int> a2 = {3, 1, 7, 11};
    std::cout << s.checkIfExist(a2) << std::endl;

    std::vector<int> a3 = {0, 0};
    std::cout << s.checkIfExist(a3) << std::endl;

    return 0;
}
