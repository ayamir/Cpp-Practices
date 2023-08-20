#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int compress(vector<char> &chars) {
        int len = chars.size();
        if (len <= 1)
            return len;
        int lastPos = 0, idx = 0;
        for (int i = 0; i < len; i++) {
            if (i == len - 1 || chars[i] != chars[i + 1]) {
                chars[lastPos++] = chars[i];
                int num = i - idx + 1;
                if (num > 1) {
                    int anchor = lastPos;
                    while (num > 0) {
                        chars[lastPos++] = num % 10 + '0';
                        num /= 10;
                    }
                    reverse(&chars[anchor], &chars[lastPos]);
                }
                idx = i + 1;
            }
        }
        return lastPos;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                          'b', 'b', 'b', 'b', 'b', 'c', 'c'};
    int num = s.compress(chars);
    for (int i = 0; i < num; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;
    return 0;
}
