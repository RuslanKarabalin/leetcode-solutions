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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        if (head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revr = new ListNode(slow->val);
        while (slow->next != nullptr) {
            slow = slow->next;
            ListNode* node = new ListNode(slow->val);
            node->next = revr;
            revr = node;
        }

        while (revr != nullptr) {
            if (head->val != revr->val) {
                return false;
            }
            head = head->next;
            revr = revr->next;
        }

        return true;
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

    ListNode* head10 = new ListNode(0);
    ListNode* next11 = new ListNode(0);
    head10->next = next11;

    ListNode* head30 = new ListNode(1);
    ListNode* next31 = new ListNode(2);
    head30->next = next31;
    ListNode* next32 = new ListNode(2);
    next31->next = next32;
    ListNode* next33 = new ListNode(1);
    next32->next = next33;

    ListNode* head40 = new ListNode(1);
    ListNode* next41 = new ListNode(0);
    head40->next = next41;
    ListNode* next42 = new ListNode(1);
    next41->next = next42;
    ListNode* next43 = new ListNode(1);
    next42->next = next43;

    Solution s;

    cout << s.isPalindrome(head00) << "\n";
    cout << s.isPalindrome(head10) << "\n";
    cout << s.isPalindrome(head30) << "\n";
    cout << s.isPalindrome(head40) << "\n";

    return 0;
}
