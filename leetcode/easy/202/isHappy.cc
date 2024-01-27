#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int getSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> set;
        while (true) {
            sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int n = 19;
    cout << s.isHappy(n);
    return 0;
}
