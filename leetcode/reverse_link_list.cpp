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
  ListNode *reverseList() {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
    return prev;
  }

  ListNode *reverseListRecursive(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }

  Solution(ListNode *head) { this->head = head; }

  void printList() {
    for (auto i = head; i != nullptr; i = i->next) {
      std::cout << i->val << " ";
    }
    std::cout << std::endl;
  }

private:
  ListNode *head;
};

int main(int argc, char *argv[]) {
  ListNode head(1);
  ListNode first(2);
  ListNode second(3);
  ListNode third(4);
  ListNode forth(5);

  head.next = &first;
  first.next = &second;
  second.next = &third;
  third.next = &forth;

  Solution *root = new Solution(&head);
  root->printList();

  root->reverseList();
  root->printList();

  return 0;
}
