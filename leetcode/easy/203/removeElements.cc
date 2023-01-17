#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *p = head, *q = head;
        while (p) {
            if (p->val == val) {
                if (p == head) {
                    head = p->next;
                    delete p;
                    p = head;
                } else {
                    q->next = p->next;
                    delete p;
                    p = q->next;
                }
            } else {
                q = p;
                p = p->next;
            }
        }
        return head;
    }

    ListNode *removeElements2(ListNode *head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements2(head->next, val);
        return head->val == val ? head->next : head;
    }

    ListNode *removeElements3(ListNode *head, int val) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *temp = dummy;
        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *head = new ListNode(
        7,
        new ListNode(
            7,
            new ListNode(
                7, new ListNode(
                       7, new ListNode(7, new ListNode(7, new ListNode(7)))))));
    ListNode *emptyHead = new ListNode();
    for (ListNode *p = s.removeElements3(head, 7); p; p = p->next) {
        cout << p->val << " ";
    }
    return 0;
}
