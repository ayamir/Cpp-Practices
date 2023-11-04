#include <iostream>

using namespace std;

class LinkedList {
  public:
    struct LinkNode {
        int val;
        LinkNode *next;
        LinkNode(int val) : val(val), next(nullptr) {}
    };

    void addAtHead(int val) {
        auto node = new LinkNode(val);
        node->next = _dummyHead->next;
        _dummyHead->next = node;
        _size++;
    }

    void addAtTail(int val) {
        auto node = new LinkNode(val);
        auto curr = _dummyHead;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size)
            return;
        auto node = new LinkNode(val);
        auto curr = _dummyHead;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
        _size++;
    }

    void removeAtIndex(int index) {
        if (index > _size)
            return;
        auto curr = _dummyHead;
        int cnt = 0;
        while (cnt < index - 1) {
            curr = curr->next;
            cnt++;
        }
        auto toRemove = curr->next;
        curr->next = toRemove->next;
        delete toRemove;
        _size++;
    }

    int get(int index) {
        if (index < 0 || index > (_size - 1)) {
            return -1;
        }
        int cnt = 0;
        auto curr = _dummyHead->next;
        while (cnt < index - 1 && curr != nullptr) {
            curr = curr->next;
            cnt++;
        }
        return curr->val;
    }

    LinkedList() {
        _dummyHead = new LinkNode(0);
        _size = 0;
    }

    void iter() {
        auto curr = _dummyHead->next;
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    int size() const { return _size; }

  private:
    LinkNode *_dummyHead;
    int _size;
};

int main(int argc, char *argv[]) {
    LinkedList linkedList;
    linkedList.addAtTail(3);
    linkedList.addAtHead(1);
    linkedList.addAtHead(2);
    linkedList.addAtIndex(3, 4);
    linkedList.iter();
    linkedList.removeAtIndex(1);
    linkedList.iter();
    cout << linkedList.get(2);
    return 0;
}
