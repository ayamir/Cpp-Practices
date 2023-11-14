#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    auto pi = new int(0);
    cout << *pi << endl;
    delete pi;
    auto i = 0;
    // free stack mem is a undefined behavior.
    // g++ compile: warning, runing: no info
    // clang++ compile: no warning, runing: free(): invalid pointer
    // delete &i;
    auto pint = new const int(1034);
    delete pint;
    return 0;
}
