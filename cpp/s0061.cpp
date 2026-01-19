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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode* node = head;
        int len = 1;
        while (node->next != nullptr) {
            ++len;
            node = node->next;
        }

        if (k == 0 || k == len) {
            return head;
        }

        int n = (k % len);

        if (n == 0) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        if (n != 1) {
            ListNode* dumb = new ListNode(slow->next->val);
            dumb->next = slow->next->next;
            fast->next = head;
            slow->next = nullptr;
            return dumb;
        } else {
            fast->next = head;
            slow->next = nullptr;
            return fast;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ListNode* head0 = new ListNode(1);
    ListNode* next1 = new ListNode(2);
    ListNode* next2 = new ListNode(3);
    ListNode* next3 = new ListNode(4);
    ListNode* next4 = new ListNode(5);
    head0->next = next1;
    next1->next = next2;
    next2->next = next3;
    next3->next = next4;

    Solution s;
    ListNode* res = s.rotateRight(head0, 3);

    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\n";

    return 0;
}
