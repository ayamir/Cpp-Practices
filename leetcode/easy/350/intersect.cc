#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p = 0, q = 0;
        while (p < nums1.size() && q < nums2.size()) {
            if (nums1[p] == nums2[q]) {
                res.push_back(nums1[p]);
                p++;
                q++;
            } else if (nums1[p] > nums2[q]) {
                q++;
            } else {
                p++;
            }
        }
        return res;
    }

    vector<int> intersectHashmap(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            return intersectHashmap(nums2, nums1);
        }
        unordered_map<int, int> m;
        for (int num : nums1) {
            ++m[num];
        }
        vector<int> res;
        for (int num : nums2) {
            if (m.count(num)) {
                res.push_back(num);
                --m[num];
                if (m[num] == 0) {
                    m.erase(num);
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    auto res = s.intersectHashmap(nums1, nums2);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}
