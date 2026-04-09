#include <climits>
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    std::vector<int> findMode(TreeNode* root) {
        currVal = INT_MIN;
        currCount = 0;
        maxCount = 0;
        modes.clear();
        inorder(root);
        return modes;
    }

   private:
    std::vector<int> modes;
    int currVal;
    int currCount;
    int maxCount;

    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;

        inorder(node->left);

        if (currVal != node->val) {
            currVal = node->val;
            currCount = 0;
        }

        currCount++;

        if (currCount == maxCount) {
            modes.push_back(currVal);
        } else if (currCount > maxCount) {
            modes.clear();
            modes.push_back(currVal);
            maxCount = currCount;
        }

        inorder(node->right);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution s;
    auto result = s.findMode(root);
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
