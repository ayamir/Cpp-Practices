#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int curr;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                curr = nums2[p2++];
            } else if (p2 == n) {
                curr = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                curr = nums1[p1++];
            } else {
                curr = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = curr;
        }
        for (int i = 0; i != m + n; i++) {
            nums1[i] = sorted[i];
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 0, n = 1;
    s.merge(nums1, m, nums2, n);
    for (auto i : nums1) {
        cout << i << " ";
    }
    return 0;
}
