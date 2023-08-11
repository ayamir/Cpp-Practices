#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int len = flowerbed.size();
        int i = 0;
        while (i < len && n > 0) {
            if (flowerbed[i] == 1) {
                i += 2;
            } else if (i == len - 1 || flowerbed[i + 1] == 0) {
                n--;
                i += 2;
            } else {
                i += 3;
            }
        }
        return n <= 0;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> flowerbed = {0};
    cout << s.canPlaceFlowers(flowerbed, 1) << endl;
    return 0;
}
