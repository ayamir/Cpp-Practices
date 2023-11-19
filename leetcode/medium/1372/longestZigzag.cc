#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
    TreeNode(TreeNode *left, TreeNode *right)
        : val(1), left(left), right(right) {}
};

class Solution {
  public:
    int maxLen = 0;
    void dfs(TreeNode *node, bool isLeft, int len) {
        maxLen = max(maxLen, len);
        if (isLeft) {
            if (node->left != nullptr)
                dfs(node->left, false, len + 1);
            if (node->right != nullptr)
                dfs(node->right, true, 1);
        } else {
            if (node->right != nullptr)
                dfs(node->right, true, len + 1);
            if (node->left != nullptr)
                dfs(node->left, false, 1);
        }
    }

    int longestZigzag(TreeNode *root) {
        if (root == nullptr)
            return 0;
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxLen;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto root = new TreeNode(
        new TreeNode(nullptr,
                     new TreeNode(new TreeNode(nullptr, new TreeNode()),
                                  new TreeNode())),
        new TreeNode());
    cout << s.longestZigzag(root);
    return 0;
}
