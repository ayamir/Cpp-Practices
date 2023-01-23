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
  private:
    vector<int> inorderTree;

  public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> stk;
        long long inorder = (long long)INT_MIN - 1;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->val <= inorder) {
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }

    bool isValidBSTIter(TreeNode *root) {
        inorderTrans(root);
        for (int i = 0; i < inorderTree.size() - 1; i++) {
            if (inorderTree[i] >= inorderTree[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void inorderTrans(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        inorderTrans(root->left);
        inorderTree.push_back(root->val);
        inorderTrans(root->right);
    }

    bool isValidBSTRecu(TreeNode *root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode *root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return helper(root->left, lower, root->val) &&
               helper(root->right, root->val, upper);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    cout << s.isValidBST(root) << endl;
    return 0;
}
