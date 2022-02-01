#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
      // store original next as new prev
      ListNode *next = curr->next;
      // make original prev as new next
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  void iter(ListNode *head) {
    for (auto p = head; p != nullptr; p = p->next) {
      std::cout << p->val << std::endl;
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  ListNode fifth(5, nullptr);
  ListNode forth(4, &fifth);
  ListNode third(3, &forth);
  ListNode second(2, &third);
  ListNode first(1, &second);

  s.iter(s.reverseList(&first));

  return 0;
}
