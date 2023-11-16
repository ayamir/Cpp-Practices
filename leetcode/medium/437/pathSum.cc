#include <bits/stdc++.h>
#include <unordered_map>

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
    unordered_map<long, int> prefix;

    int dfs(TreeNode *node, long curr, int left) {
        if (node == nullptr)
            return 0;
        int ret = 0;
        int val = node->val;
        curr += val;
        if (prefix.count(curr - left)) {
            ret = prefix[curr - left];
        }
        prefix[curr]++;
        ret += dfs(node->left, curr, left) + dfs(node->right, curr, left);
        prefix[curr]--;
        return ret;
    }
    int pathSum(TreeNode *root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(
        10,
        new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)),
                     new TreeNode(2, nullptr, new TreeNode(1))),
        new TreeNode(-3, nullptr, new TreeNode(11)));
    cout << s.pathSum(root, 8);
    return 0;
}
