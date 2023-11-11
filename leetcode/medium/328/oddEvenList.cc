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
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr)
            return head;
        ListNode *oddPtr = head;
        ListNode *firstEven = head->next;
        ListNode *evenPtr = head->next;
        while (evenPtr != nullptr && evenPtr->next != nullptr) {
            oddPtr->next = evenPtr->next;
            oddPtr = oddPtr->next;
            evenPtr->next = oddPtr->next;
            evenPtr = evenPtr->next;
        }
        oddPtr->next = firstEven;
        return head;
    }

    void iterList(ListNode *head) {
        auto curr = head;
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *head = new ListNode(
        1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto curr = s.oddEvenList(head);
    s.iterList(curr);
    return 0;
}
