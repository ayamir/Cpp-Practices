#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
  public:
    bool check(string substr, string str) {
        int lenx = (int)str.length() / (int)substr.length();
        string res = "";
        for (int i = 1; i <= lenx; i++) {
            res += substr;
        }
        return res == str;
    }
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        auto substr = str1.substr(0, __gcd(len1, len2));
        if (check(substr, str1) && check(substr, str2))
            return substr;
        return "";
    }

    string gcdOfStringsMath(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0, __gcd((int)str1.length(), (int)str2.length()));
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto str1 = "ABABAB";
    auto str2 = "AB";
    cout << s.gcdOfStrings(str1, str2) << endl;
    return 0;
}
