#include <cstdio>
#include <iostream>
#include <unordered_map>

struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  private:
    std::unordered_map<int, Node *> cache;
    // dummy head
    Node *head;
    // dummy tail
    Node *tail;
    // size as current number
    int size;
    // capacity as max number
    int capacity;

  public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void addToHead(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node *node) {
        removeNode(node);
        addToHead(node);
    }

    Node *removeTail() {
        Node *node = tail->prev;
        removeNode(node);
        return node;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        Node *node = cache[key];
        moveToHead(node);
        return node->value;
    }
    void put(int key, int value) {
        if (!cache.count(key)) {
            Node *node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            size += 1;
            // remove tail if over capacity
            if (size > capacity) {
                Node *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size -= 1;
            }
        } else {
            // founded
            Node *node = cache[key];
            // update value
            node->value = value;
            // move to head
            moveToHead(node);
        }
    }
};

int main(int argc, char *argv[]) {
    int capacity = 10, key = 1, value = 2;
    LRUCache *obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key, value);
    return 0;
}
