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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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
    ListNode* next12 = new ListNode(3);
    next11->next = next12;
    ListNode* next13 = new ListNode(4);
    next12->next = next13;
    ListNode* next14 = new ListNode(5);
    next13->next = next14;
    ListNode* next15 = new ListNode(6);
    next14->next = next15;

    Solution s;
    ListNode* res;

    res = s.middleNode(head00);
    cout << res->val << std::endl;

    res = s.middleNode(head10);
    cout << res->val << std::endl;

    return 0;
}
