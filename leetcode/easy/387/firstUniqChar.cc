#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int firstUniqChar(string s) {
        int array[26] = {0};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            array[s[i] - 'a']++;
        }
        for (int i = 0; i < n; ++i) {
            if (array[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string str = "loveleetcode";
    cout << s.firstUniqChar(str) << endl;
    return 0;
}
