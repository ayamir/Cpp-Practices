#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
  public:
    ListNode *deleteMiddle(ListNode *head) {
        if (head->next == nullptr) {
            return nullptr;
        }
        auto slow = head;
        auto fast = head;
        ListNode *pre = nullptr;
        while (fast && fast->next != nullptr) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
