#include <bits/stdc++.h>
#include <list>
#include <utility>
#include <vector>

using namespace std;

class MyHashMap {
  private:
    vector<list<pair<int, int>>> m_data;
    static const int base = 769;
    static int hash(int key) { return key % base; }

  public:
    MyHashMap() : m_data(base) {}

    void put(int key, int value) {
        int h = hash(key);
        for (auto &p : m_data[h]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        m_data[h].emplace_back(key, value);
    }

    int get(int key) {
        int h = hash(key);
        for (auto &p : m_data[h]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = m_data[h].begin(); it != m_data[h].end(); ++it) {
            if (it->first == key) {
                m_data[h].erase(it);
                return;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    MyHashMap *obj = new MyHashMap();
    obj->put(1, 1);
    int param_2 = obj->get(1);
    cout << param_2 << endl;
    obj->remove(1);
    return 0;
}
