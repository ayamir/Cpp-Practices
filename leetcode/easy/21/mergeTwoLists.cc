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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *res = nullptr;
        if (list1->val > list2->val) {
            res = list2;
        } else {
            res = list1;
        }
        while (list1 && list2) {
            if (list1->val > list2->val) {
                swap(list1, list2);
            }
            ListNode *next = list1->next;
            if (!next || next->val > list2->val) {
                list1->next = list2;
                list1 = next;
            } else {
                list1 = next;
            }
        }
        return res;
    }

    ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        } else if (list1->val < list2->val) {
            list1->next = mergeTwoLists2(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists2(list1, list2->next);
            return list2;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(2, new ListNode(3, new ListNode(4)));
    auto res = s.mergeTwoLists(list1, list2);
    for (ListNode *p = res; p; p = p->next) {
        cout << p->val << " ";
    }
    return 0;
}
