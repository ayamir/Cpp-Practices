#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> s;
        while (head) {
            if (s.count(head)) {
                return true;
            }
            s.insert(head);
            head = head->next;
        }
        return false;
    }

    bool hasCycle2(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
