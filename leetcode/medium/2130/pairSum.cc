#include <bits/stdc++.h>
#include <climits>
#include <vector>

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
    int pairSum(ListNode *head) {
        if (head == nullptr)
            return 0;
        int ret = INT_MIN;
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *curr = head;
        int len = 0;
        while (curr != nullptr) {
            ++len;
            curr = curr->next;
        }
        curr = dummyHead->next;
        int leftSize = len / 2;
        int left[leftSize];
        int i = 0;
        for (; i < leftSize; ++i) {
            left[i] = curr->val;
            curr = curr->next;
        }
        while (curr != nullptr) {
            int sum = left[len - i - 1] + curr->val;
            ret = max(sum, ret);
            curr = curr->next;
            ++i;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *head =
        new ListNode(5, new ListNode(5, new ListNode(2, new ListNode(8))));
    cout << s.pairSum(head);
    return 0;
}
