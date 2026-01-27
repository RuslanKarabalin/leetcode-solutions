#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        const auto& x = v[i];
        out << x;
        if (i < v.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        int len = 1;
        ListNode* l = head;
        while (l->next != nullptr) {
            l = l->next;
            ++len;
        }

        if (len == n) {
            return head->next;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        int i = 1;
        while (fast != nullptr && fast->next != nullptr && i < (len - n)) {
            slow = slow->next;
            fast = fast->next;
            ++i;
        }
        slow->next = fast->next;

        return head;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int n0 = 2;
    ListNode* head00 = new ListNode(1);
    ListNode* next01 = new ListNode(2);
    ListNode* next02 = new ListNode(3);
    ListNode* next03 = new ListNode(4);
    ListNode* next04 = new ListNode(5);
    head00->next = next01;
    next01->next = next02;
    next02->next = next03;
    next03->next = next04;

    std::cout << s.removeNthFromEnd(head00, n0)->val << "\n-" << std::endl;

    int n1 = 2;
    ListNode* head10 = new ListNode(1);
    ListNode* next11 = new ListNode(2);
    head10->next = next11;

    std::cout << s.removeNthFromEnd(head10, n1)->val << "\n-" << std::endl;

    return 0;
}
