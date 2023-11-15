#include <bits/stdc++.h>
#include <stack>

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
    int dfs(TreeNode *node, int max) {
        if (node == nullptr)
            return 0;
        int ret = 0;
        if (node->val >= max) {
            ret++;
            max = node->val;
        }
        ret += dfs(node->left, max) + dfs(node->right, max);
        return ret;
    }
    int goodNodes(TreeNode *root) { return dfs(root, root->val); }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root =
        new TreeNode(3, new TreeNode(1, new TreeNode(3), nullptr),
                     new TreeNode(4, new TreeNode(1), new TreeNode(5)));
    cout << s.goodNodes(root);
    return 0;
}
