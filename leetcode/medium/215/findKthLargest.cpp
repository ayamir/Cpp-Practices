#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    void initMaxHeap(vector<int> &nums, int i, int heap_size) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heap_size && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heap_size && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            initMaxHeap(nums, largest, heap_size);
        }
    }

    void buildMaxHeap(vector<int> &nums, int heap_size) {
        for (int i = heap_size / 2; i >= 0; --i) {
            initMaxHeap(nums, i, heap_size);
        }
    }

    int findKthLargestMaxHeap(vector<int> &nums, int k) {
        int heap_size = nums.size();
        buildMaxHeap(nums, heap_size);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heap_size;
            initMaxHeap(nums, 0, heap_size);
        }
        return nums[0];
    }

    inline int partition(vector<int> &nums, int l, int r) {
        int x = nums[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return (i + 1);
    }

    inline int qPartition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    int qSelect(vector<int> &nums, int l, int r, int index) {
        int q = qPartition(nums, l, r);
        if (q == index) {
            return nums[q];
        } else {
            return q < index ? qSelect(nums, q + 1, r, index)
                             : qSelect(nums, l, q - 1, index);
        }
    }

    int findKthLargestDC(vector<int> &nums, int k) {
        srand(time(0));
        return qSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargestDC(nums, 4) << endl;
    return 0;
}
