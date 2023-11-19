#include <bits/stdc++.h>
#include <queue>
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
    void dfs(TreeNode *node, vector<int> &vec, int depth) {
        if (node == nullptr)
            return;
        if (depth == vec.size())
            vec.push_back(node->val);
        depth++;
        dfs(node->right, vec, depth);
        dfs(node->left, vec, depth);
    }
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ret;
        if (root == nullptr)
            return ret;
        dfs(root, ret, 0);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), nullptr);
    auto ret = s.rightSideView(root);
    for (const auto &v : ret) {
        cout << v << " ";
    }
    return 0;
}
