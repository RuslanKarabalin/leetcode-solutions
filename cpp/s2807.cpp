#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = head ? head->next : nullptr;
        while (next != nullptr) {
            int newVal = gcd(cur->val, next->val);
            ListNode* newNode = new ListNode(newVal);
            newNode->next = next;
            cur->next = newNode;
            cur = next;
            next = next->next;
        }
        return head;
    }

   private:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << ", ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ListNode* li4 = new ListNode(3);
    ListNode* li3 = new ListNode(10, li4);
    ListNode* li2 = new ListNode(6, li3);
    ListNode* li1 = new ListNode(18, li2);

    Solution s;
    ListNode* result = s.insertGreatestCommonDivisors(li1);
    printList(result);

    return 0;
}
