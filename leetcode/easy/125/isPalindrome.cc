#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string str = "0P";
    cout << s.isPalindrome(str);
    return 0;
}
