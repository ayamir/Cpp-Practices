#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        int strSize = haystack.size();
        int subSize = needle.size();
        for (int i = 0; i <= strSize - subSize; i++) {
            int j = i, k = 0;
            while (k < subSize && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if (k == subSize)
                return i;
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.strStr("leetcode", "leet");
    return 0;
}
