#include <bits/stdc++.h>
#include <vector>

using namespace std;

class MinStack {
  private:
    vector<int> stk;
    int minValue;

  public:
    MinStack() {}
    void push(int val) {
        if (stk.empty()) {
            minValue = val;
            stk.push_back(0);
        } else {
            int diff = val - minValue;
            stk.push_back(diff);
            minValue = diff < 0 ? val : minValue;
        }
    }
    void pop() {
        if (!stk.empty()) {
            int top = stk.back();
            minValue = top < 0 ? (minValue - top) : minValue;
            stk.pop_back();
        }
    }
    int top() {
        int topDiff = stk.back();
        if (topDiff < 0) {
            return minValue;
        }
        return topDiff + minValue;
    }
    int getMin() { return minValue; }
};

int main(int argc, char *argv[]) {
    MinStack s;
    s.push(-1);
    s.push(-2);
    s.push(-3);
    cout << s.getMin() << endl;
    s.push(0);
    s.pop();
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}
