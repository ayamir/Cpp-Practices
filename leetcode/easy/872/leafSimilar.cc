#include <bits/stdc++.h>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
  public:
    void dfs(TreeNode *node, vector<int> &seq) {
        if (!node->left && !node->right) {
            seq.push_back(node->val);
        } else {
            if (node->left) {
                dfs(node->left, seq);
            }
            if (node->right) {
                dfs(node->right, seq);
            }
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> seq1, seq2;
        if (root1 != nullptr)
            dfs(root1, seq1);
        if (root2 != nullptr)
            dfs(root2, seq2);
        return seq1 == seq2;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
