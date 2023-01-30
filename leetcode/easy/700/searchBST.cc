#include <bits/stdc++.h>

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
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        } else if (root->val > val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
    TreeNode *searchBSTIter(TreeNode *root, int val) {
        while (root) {
            if (root->val == val) {
                return root;
            } else if (root->val > val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout << s.searchBST(root, 2)->val << endl;
    return 0;
}
