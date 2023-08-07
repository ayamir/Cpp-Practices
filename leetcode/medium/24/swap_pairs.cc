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
    ListNode *swapPairs(ListNode *head) {
        auto pre = new ListNode(0);
        pre->next = head;
        auto temp = pre;
        // group length = 2
        while (temp->next != nullptr && temp->next->next != nullptr) {
            auto curr = temp->next;
            auto next = curr->next;
            temp->next = next;
            curr->next = next->next;
            next->next = curr;
            temp = curr;
        }
        return pre->next;
    }

    ListNode *swapPairsRecu(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *newHead = head->next;
        head->next = swapPairsRecu(newHead->next);
        newHead->next = head;
        return newHead;
    }

    void iter(ListNode *head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *head =
        new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    // ListNode *head = new ListNode(0, nullptr);
    auto res = s.swapPairsRecu(head);
    s.iter(res);
    return 0;
}
