#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
  private:
    unordered_map<char, int> oriMap, cntMap;

    bool check() {
        for (const auto &p : oriMap) {
            if (cntMap[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

  public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) {
            return "";
        }
        for (const auto &c : t) {
            ++oriMap[c];
        }
        string res;
        int start = 0, end = -1;
        int len = INT_MAX, resStart = -1;
        while (end < m) {
            if (oriMap.find(s[++end]) != oriMap.end()) {
                ++cntMap[s[end]];
            }
            // 满足覆盖条件
            while (check() && start <= end) {
                if (end - start + 1 < len) {
                    len = end - start + 1;
                    resStart = start;
                }
                if (oriMap.find(s[start]) != oriMap.end()) {
                    --cntMap[s[start]];
                }
                ++start;
            }
        }
        return resStart == -1 ? "" : s.substr(resStart, len);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string str = "ADOBECODEBANC";
    string t = "ABC";
    cout << s.minWindow(str, t);
    return 0;
}
