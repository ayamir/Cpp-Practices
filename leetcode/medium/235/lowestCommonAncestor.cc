#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *curr = root;
        if (p->val > q->val) {
            swap(p, q);
        }
        while (curr != nullptr) {
            if (curr->val >= p->val && curr->val <= q->val) {
                return curr;
            }
            if (curr->val > q->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return nullptr;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
