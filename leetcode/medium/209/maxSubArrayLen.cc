#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int maxSubArrayLen(string s) {
        int n = s.size();
        if (n < 2) {
            return n;
        }
        int res = 1, start = 0, end = 0;
        unordered_set<char> set;
        while (end < n) {
            char curr = s[end];
            while (set.find(curr) != set.end()) {
                set.erase(s[start]);
                start++;
            }
            res = max(res, end - start + 1);
            set.insert(curr);
            end++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string str = "aab";
    cout << s.maxSubArrayLen(str);
    return 0;
}
