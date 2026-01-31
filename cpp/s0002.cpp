#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        ListNode* tmp = sum;
        int over = 0;
        ListNode* ll1 = l1;
        ListNode* ll2 = l2;
        while (ll1) {
            tmp->val = ll1->val;
            ll1 = ll1->next;
            if (ll1) {
                tmp->next = new ListNode();
            }
            tmp = tmp->next;
        }
        tmp = sum;
        while (ll2) {
            tmp->val += ll2->val;
            ll2 = ll2->next;
            if (ll2 && !tmp->next) {
                tmp->next = new ListNode();
            }
            tmp = tmp->next;
        }
        tmp = sum;
        while (tmp) {
            if (tmp->val + over > 9) {
                tmp->val += over;
                over = tmp->val / 10;
                tmp->val %= 10;
            } else {
                tmp->val += over;
                over = tmp->val / 10;
            }
            if (tmp->next) {
                tmp = tmp->next;
            } else {
                break;
            }
        }
        if (over > 0) {
            tmp->next = new ListNode(over);
        }
        return sum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    ListNode* head00 = new ListNode(2);
    ListNode* next01 = new ListNode(4);
    head00->next = next01;
    ListNode* next02 = new ListNode(3);
    next01->next = next02;

    ListNode* head10 = new ListNode(5);
    ListNode* next11 = new ListNode(6);
    head10->next = next11;
    ListNode* next12 = new ListNode(4);
    next11->next = next12;

    ListNode* res = s.addTwoNumbers(head00, head10);
    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
