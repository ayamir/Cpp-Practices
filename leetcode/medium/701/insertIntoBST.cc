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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        auto curr = root;
        while (curr) {
            if (curr->val > val) {
                if (curr->left) {
                    curr = curr->left;
                } else {
                    curr->left = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->right) {
                    curr = curr->right;
                } else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }

    void printTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    auto res = s.insertIntoBST(root, 5);
    s.printTree(res);
    return 0;
}
