#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        vector<string> level;
        string curr = "";
        for (int idx = 0; idx < words.size();) {
            string word = words[idx];
            if (curr.size() + level.size() + word.size() <= maxWidth) {
                curr += word;
                level.emplace_back(word);
                idx++;
            } else {
                int leftSpace = maxWidth - curr.size();
                int spaceNum = level.size() - 1;
                int averageSpace = leftSpace;
                int modSpace = 0;
                if (spaceNum != 0) {
                    averageSpace = leftSpace / spaceNum;
                    if (spaceNum != 1) {
                        modSpace = leftSpace % spaceNum;
                    }
                }
                string averageSpaceToAppend = "";
                for (int i = 0; i < averageSpace; i++) {
                    averageSpaceToAppend.append(" ");
                }
                curr = "";
                for (int i = 0; i < spaceNum; i++) {
                    curr += level[i] + averageSpaceToAppend;
                    if (modSpace > 0) {
                        curr += ' ';
                        modSpace--;
                    }
                }
                if (spaceNum == 0) {
                    curr += level[0] + averageSpaceToAppend;
                } else {
                    curr += level[spaceNum];
                }
                res.emplace_back(curr);
                curr = "";
                level.clear();
            }
        }
        int levelSize = level.size();
        if (levelSize != 0) {
            curr = "";
            for (int i = 0; i < levelSize - 1; i++) {
                curr += level[i] + " ";
            }
            curr += level[levelSize - 1];
            while (curr.size() < maxWidth) {
                curr.append(" ");
            }
        }
        res.emplace_back(curr);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> words = {"ask", "not", "what", "your", "country", "can",
                            "do",  "for", "you",  "ask",  "what",    "you",
                            "can", "do",  "for",  "your", "country"};
    auto res = s.fullJustify(words, 16);
    for (const string &str : res) {
        cout << str << "+" << endl;
    }
    return 0;
}
