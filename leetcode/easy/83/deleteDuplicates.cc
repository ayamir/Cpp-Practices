#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        ListNode *p = head;
        while (head->next) {
            if (head->val == head->next->val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return p;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *head = new ListNode(
        1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    for (ListNode *p = s.deleteDuplicates(head); p; p = p->next) {
        cout << p->val << " ";
    }
    return 0;
}
