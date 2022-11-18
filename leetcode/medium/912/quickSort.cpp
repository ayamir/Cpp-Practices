#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    vector<int> tmp;
    void iter(vector<int> &nums) {
        for (auto &i : nums) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    vector<int> sortArray(vector<int> &nums) {
        srand((unsigned)time(NULL));
        int r = nums.size() - 1;
        quickSort(nums, 0, (int)r);
        return nums;
    }

    vector<int> sortArrayDC(vector<int> &nums) {
        tmp.resize((int)nums.size(), 0);
        int r = nums.size() - 1;
        mergeSort(nums, 0, r);
        return nums;
    }

    vector<int> sortArrayHeap(vector<int> &nums) {
        heapSort(nums);
        return nums;
    }

  private:
    void quickSort(vector<int> &nums, int p, int r) {
        if (p < r) {
            int q = random_partition(nums, p, r);
            quickSort(nums, p, q - 1);
            quickSort(nums, q + 1, r);
        }
        // no need to return
    }

    // random is must
    int random_partition(vector<int> &nums, int p, int r) {
        int i = rand() % (r - p + 1) + p;
        std::swap(nums[r], nums[i]);
        return partition(nums, p, r);
    }

    int partition(vector<int> &a, int p, int r) {
        int x = a[r];
        int i = p - 1;
        for (int j = p; j <= r - 1; ++j) {
            if (a[j] <= x) {
                i += 1;
                std::swap(a[i], a[j]);
            }
        }
        std::swap(a[i + 1], a[r]);
        return i + 1;
    }

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[cnt++] = nums[i++];
            } else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }

        for (int i = 0; i < r - l + 1; ++i) {
            nums[i + l] = tmp[i];
        }
    }

    void maxHeapify(vector<int> &nums, int i, int length) {
        while (i * 2 + 1 <= length) {
            int lson = (i / 2) + 1;
            int rson = (i / 2) + 2;
            int large;
            if (lson <= length && nums[lson] > nums[i]) {
                large = lson;
            } else {
                large = i;
            }
            if (rson <= length && nums[rson] > nums[large]) {
                large = rson;
            }
            if (large != i) {
                std::swap(nums[i], nums[large]);
                i = large;
            } else {
                break;
            }
        }
    }

    void buildMaxHeap(vector<int> &nums, int length) {
        for (int i = length / 2; i >= 0; --i) {
            maxHeapify(nums, i, length);
        }
    }

    void heapSort(vector<int> &nums) {
        int length = nums.size() - 1;
        buildMaxHeap(nums, length);
        for (int i = length; i >= 1; --i) {
            std::swap(nums[i], nums[0]);
            length -= 1;
            maxHeapify(nums, 0, length);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    s.sortArrayHeap(nums);
    s.iter(nums);
    return 0;
}
