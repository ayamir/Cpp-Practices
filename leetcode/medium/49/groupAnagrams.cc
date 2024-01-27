#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        for (const auto &str : strs) {
            string key(26, '0');
            for (const auto &c : str) {
                key[c - 'a']++;
            }
            hash[key].emplace_back(str);
        }
        for (const auto &pair : hash) {
            res.emplace_back(pair.second);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = s.groupAnagrams(strs);
    for (const auto &v : res) {
        for (const auto &s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
