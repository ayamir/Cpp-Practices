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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }
        int leftSum = targetSum - root->val;
        bool left = hasPathSum(root->left, leftSum);
        bool right = hasPathSum(root->right, leftSum);
        return left || right || (leftSum == 0 && !root->left && !root->right);
    }

    void printTree(TreeNode *root) {
        if (!root) {
            return;
        }
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }

    bool hasPathSumIter(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }
        queue<TreeNode *> q;
        queue<int> qSum;
        q.push(root);
        qSum.push(root->val);
        while (!q.empty() && !qSum.empty()) {
            auto curr = q.front();
            q.pop();
            auto currSum = qSum.front();
            qSum.pop();
            if (!curr->left && !curr->right && currSum == targetSum) {
                return true;
            }
            if (curr->left) {
                q.push(curr->left);
                qSum.push(currSum + curr->left->val);
            }
            if (curr->right) {
                q.push(curr->right);
                qSum.push(currSum + curr->right->val);
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    cout << s.hasPathSumIter(root, 22) << endl;
    return 0;
}
