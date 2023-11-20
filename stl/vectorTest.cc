#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"

bool is_reserve = false;

class Point {
  private:
    int x;
    int y;

  public:
    Point(int x, int y) : x(x), y(y) {
        printf("%sConstruct (%d, %d)%s\n", GRN, x, y, RESET);
    }
    Point(Point &p) : x(p.x), y(p.y) {
        printf("%sCopy (%d, %d)%s\n", BLU, x, y, RESET);
    }
    Point(Point &&rhs) : x(rhs.x), y(rhs.y) {
        printf("%sMove (%d, %d)%s\n", YEL, x, y, RESET);
    }
    ~Point() { printf("%sDestruct (%d, %d)%s\n", RED, x, y, RESET); }
};

struct EPNotWork {
    int noConstructor;
};

void push_back_test() {
    vector<Point> vec;
    if (is_reserve) {
        vec.reserve(3);
    }
    vec.push_back(Point(1, 2));
    cout << endl;
    vec.push_back(Point(2, 3));
    cout << endl;
    vec.push_back(Point(3, 4));
    cout << endl;
}

void emplace_back_test() {
    vector<Point> vec;
    if (is_reserve) {
        vec.reserve(3);
    }
    vec.emplace_back(1, 2);
    cout << endl;
    vec.emplace_back(2, 3);
    cout << endl;
    vec.emplace_back(3, 4);
    cout << endl;
}

void test_efficency() {
    cout << "push_back_test:" << endl;
    push_back_test();
    cout << endl;
    cout << "emplace_back_test:" << endl;
    emplace_back_test();
}

void test_for_strcut() {
    vector<EPNotWork> vec;
    vec.push_back({0});
    // Error
    // vec.emplace_back({0});
    // No Error after declare Struct name explicitly
    vec.emplace_back<EPNotWork>({0});
}

int main(int argc, char *argv[]) {
    cout << "No reserve" << endl;
    test_efficency();
    cout << endl;
    cout << "Reserve" << endl;
    is_reserve = true;
    test_efficency();
    return 0;
}
