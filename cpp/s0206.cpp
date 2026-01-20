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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;
        ListNode* next = head->next;
        curr->next = nullptr;
        while (next != nullptr) {
            ListNode* nextnext = next->next;
            next->next = curr;
            curr = next;
            next = nextnext;
        }
        return curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ListNode* head00 = new ListNode(1);
    ListNode* next01 = new ListNode(2);
    head00->next = next01;
    ListNode* next02 = new ListNode(3);
    next01->next = next02;
    ListNode* next03 = new ListNode(4);
    next02->next = next03;
    ListNode* next04 = new ListNode(5);
    next03->next = next04;

    ListNode* head10 = new ListNode(1);
    ListNode* next11 = new ListNode(2);
    head10->next = next11;

    ListNode* head20 = new ListNode(1);

    Solution s;
    ListNode* res;

    res = s.reverseList(head00);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\n";

    res = s.reverseList(head10);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\n";

    res = s.reverseList(head20);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\n";

    return 0;
}
