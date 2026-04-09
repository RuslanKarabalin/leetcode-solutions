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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;

        while (current != nullptr) {
            int sum = 0;
            ListNode* ptr = current->next;
            while (ptr != nullptr) {
                sum += ptr->val;
                if (sum == 0) {
                    current->next = ptr->next;
                }
                ptr = ptr->next;
            }
            current = current->next;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ListNode* node5 = new ListNode(1);
    ListNode* node4 = new ListNode(3, node5);
    ListNode* node3 = new ListNode(-3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution s;
    ListNode* result = s.removeZeroSumSublists(node1);
    printList(result);

    return 0;
}
