#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> umap;
        for (const auto &value : arr) {
            umap[value]++;
        }
        unordered_set<int> times;
        for (const auto &value : umap) {
            times.insert(value.second);
        }
        return times.size() == umap.size();
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << s.uniqueOccurrences(arr);
    return 0;
}
