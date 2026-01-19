#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* node = head;
        while (list1 != nullptr && list2 != nullptr) {
            node->next = new ListNode();
            node = node->next;
            if (list1->val < list2->val) {
                node->val = list1->val;
                list1 = list1->next;
            } else {
                node->val = list2->val;
                list2 = list2->next;
            }
        }

        while (list1 != nullptr) {
            node->next = new ListNode();
            node = node->next;
            node->val = list1->val;
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            node->next = new ListNode();
            node = node->next;
            node->val = list2->val;
            list2 = list2->next;
        }

        node = nullptr;

        return head->next;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
