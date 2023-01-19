#include <bits/stdc++.h>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversalIter(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (!stk.empty() || curr != nullptr) {
            while (curr != nullptr) {
                res.push_back(curr->val);
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            curr = curr->right;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
