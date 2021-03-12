#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    int ret = 0;
    for (int n : nums) {
      ret ^= n;
    }
    int div = 1;
    while ((div & ret) == 0) {
      div <<= 1;
    }
    int a = 0, b = 0;
    for (int n : nums) {
      if (div & n) {
        a ^= n;
      } else {
        b ^= n;
      }
    }
    return vector<int>{a, b};
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {4, 1, 4, 6};
  Solution *s = new Solution;
  auto res = s->singleNumber(nums);
  for (int n : res) {
    cout << n << endl;
  }
  return 0;
}
