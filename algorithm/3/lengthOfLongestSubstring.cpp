#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int size = s.size();
    int j = -1, res = 0;
    for (int i = 0; i < size; i++) {
      if (i != 0) {
        set.erase(s[i - 1]);
      }
      for (; j + 1 < size && !set.count(s[j + 1]); j++) {
        set.insert(s[j + 1]);
      }
      res = max(res, j - i + 1);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string str = "abcabcbb";
  auto res = s.lengthOfLongestSubstring(str);
  cout << res << endl;
  return 0;
}
