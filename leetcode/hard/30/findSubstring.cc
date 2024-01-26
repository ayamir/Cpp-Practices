#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int unit = words[0].size();
        int len = words.size() * unit;
        unordered_map<string, int> wordCount;
        for (const string &word : words) {
            wordCount[word]++;
        }
        vector<int> res;
        for (int i = 0; i < unit; i++) {
            int start = i, end = i, count = 0;
            unordered_map<string, int> window;
            while (end + unit <= s.size()) {
                string word = s.substr(end, unit);
                end += unit;
                if (wordCount.find(word) != wordCount.end()) {
                    window[word]++;
                    count++;
                    while (window[word] > wordCount[word]) {
                        string startWord = s.substr(start, unit);
                        window[startWord]--;
                        count--;
                        start += unit;
                    }
                    if (count == words.size()) {
                        res.emplace_back(start);
                    }
                } else {
                    window.clear();
                    count = 0;
                    start = end;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = {"fooo", "barr", "wing", "ding", "wing"};
    auto res = s.findSubstring(str, words);
    for (const auto &v : res) {
        cout << v << endl;
    }
    return 0;
}
