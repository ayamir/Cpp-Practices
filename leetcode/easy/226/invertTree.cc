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
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return root;
        }
        auto left = invertTree(root->left);
        auto right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    void printTree(TreeNode *root) {
        if (!root) {
            return;
        }
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }

    TreeNode *invertTreeIter(TreeNode *root) {
        if (!root) {
            return root;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (!curr) {
                continue;
            }
            auto left = curr->left;
            curr->left = curr->right;
            curr->right = left;
            q.push(curr->left);
            q.push(curr->right);
        }
        return root;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    s.printTree(root);
    cout << endl;
    auto curr = s.invertTreeIter(root);
    s.printTree(curr);
    return 0;
}
