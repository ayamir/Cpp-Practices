#include <bits/stdc++.h>
#include <queue>

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
    int maxDepth(TreeNode *root) {
        int res = 0;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ++res;
        }
        return res;
    }

    int maxDepthRec(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepthRec(root->left), maxDepthRec(root->right)) + 1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
