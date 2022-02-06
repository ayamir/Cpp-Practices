#include <iostream>
#include <utility>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy_head = new ListNode{0};
    dummy_head->next = head;
    ListNode *prev = dummy_head;

    while (head != nullptr) {
      ListNode *tail = prev;
      for (int i = 0; i < k; ++i) {
        tail = tail->next;
        if (!tail) {
          return dummy_head->next;
        }
      }
      ListNode *next = tail->next;
      auto result = subReverse(head, tail);
      head = result.first;
      tail = result.second;

      prev->next = head;
      tail->next = next;
      prev = tail;
      head = tail->next;
    }
    return dummy_head->next;
  }

  std::pair<ListNode *, ListNode *> subReverse(ListNode *head, ListNode *tail) {
    ListNode *prev = tail->next;
    ListNode *curr = head;
    while (prev != tail) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return {tail, head};
  }

  ListNode *reverseKGroupLen(ListNode *head, int k) {
    ListNode *dummy_head = new ListNode{0};
    ListNode *prev = dummy_head;
    ListNode *curr = head;
    ListNode *next = nullptr;
    dummy_head->next = head;

    int len = 0;
    for (auto p = head; p != nullptr; p = p->next) {
      ++len;
    }
    for (int i = 0; i < len / k; ++i) {
      for (int j = 0; j < k - 1; ++j) {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
      }
      prev = curr;
      curr = prev->next;
    }
    return dummy_head->next;
  }

  void iter(ListNode *head) {
    for (auto p = head; p != nullptr; p = p->next) {
      std::cout << p->val << " ";
    }
    std::cout << std::endl;
  }
};

int main(int argc, char *argv[]) {
  ListNode fifth{5, nullptr};
  ListNode forth{4, &fifth};
  ListNode third{3, &forth};
  ListNode second{2, &third};
  ListNode first{1, &second};

  Solution s;
  int group_size = 3;
  auto head = s.reverseKGroupLen(&first, group_size);
  s.iter(head);

  return 0;
}
