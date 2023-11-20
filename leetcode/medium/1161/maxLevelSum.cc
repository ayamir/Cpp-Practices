#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
  public:
    vector<int> sumVec;
    void dfs(TreeNode *node, int level) {
        if (level == sumVec.size()) {
            sumVec.push_back(node->val);
        } else {
            sumVec[level] += node->val;
        }
        if (node->left != nullptr) {
            dfs(node->left, level + 1);
        }
        if (node->right != nullptr) {
            dfs(node->right, level + 1);
        }
    }
    int maxLevelSumDFS(TreeNode *root) {
        dfs(root, 0);
        int ret = 0;
        for (int i = 0; i < sumVec.size(); ++i) {
            if (sumVec[i] > sumVec[ret]) {
                ret = i;
            }
        }
        return ret + 1;
    }
    int maxLevelSumBFS(TreeNode *root) {
        int ret = 1;
        if (root == nullptr)
            return ret;
        int maxSum = root->val;
        vector<TreeNode *> q{root};
        for (int level = 1; !q.empty(); ++level) {
            vector<TreeNode *> vec;
            int sum = 0;
            for (const auto &node : q) {
                sum += node->val;
                if (node->left != nullptr) {
                    vec.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    vec.emplace_back(node->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                ret = level;
            }
            q = std::move(vec);
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(
        1, new TreeNode(7, new TreeNode(7), new TreeNode(-8)), new TreeNode(0));
    cout << s.maxLevelSumBFS(root);
    return 0;
}
