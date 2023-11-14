#include <iostream>
#include <vector>

using namespace std;

vector<int> *func1() {
    auto vec = new vector<int>();
    return vec;
}

vector<int> *func2(vector<int> *vec) {
    int a;
    cin >> a;
    vec->push_back(a);
    return vec;
}

void func3(vector<int> *vec) {
    for (const auto &e : *vec) {
        cout << e << " " << &e << endl;
    }
    cout << vec << endl;
    delete vec;
}

int main(int argc, char *argv[]) {
    auto vec = func1();
    func3(func2(vec));
    return 0;
}
