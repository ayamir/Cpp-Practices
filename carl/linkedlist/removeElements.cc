#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int n) : val(n), next(nullptr) {}
    ListNode(int n, ListNode *next) : val(n), next(next) {}
};

using namespace std;

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(0, head);
        auto curr = dummyHead;
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                auto tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            } else {
                curr = curr->next;
            }
        }
        return dummyHead->next;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *head = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                6, new ListNode(
                       3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    auto node = s.removeElements(head, 6);
    while (node != nullptr) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}
