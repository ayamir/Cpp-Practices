#include <bits/stdc++.h>
#include <stack>

using namespace std;

class MyQueue {
  private:
    stack<int> in, out;

    void in2out() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }

  public:
    MyQueue() {}

    void push(int x) { in.push(x); }

    int pop() {
        if (out.empty()) {
            in2out();
        }
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        if (out.empty()) {
            in2out();
        }
        return out.top();
    }

    bool empty() { return in.empty() && out.empty(); }
};

int main(int argc, char *argv[]) {
    MyQueue *obj = new MyQueue();
    int x = 1;
    obj->push(x);
    int param_2 = obj->peek();
    int param_3 = obj->pop();
    bool param_4 = obj->empty();
    cout << param_2 << " " << param_3 << " " << param_4 << endl;
    return 0;
}
