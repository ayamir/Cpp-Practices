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
    bool isSymmetric(TreeNode *root) {
        bool res = true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node == nullptr) {
                    level.push_back(INT_MIN);
                    continue;
                }
                level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            res = res && isSymmetricVec(level);
            if (!res) {
                break;
            }
        }
        return res;
    }

    bool isSymmetricVec(vector<int> &level) {
        int size = level.size();
        if (size % 2 != 0 && size != 1) {
            return false;
        }
        for (int i = 0; i < size / 2; i++) {
            if (level[i] != level[size - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    bool check(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return left->val == right->val && check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetricRec(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return check(root->left, root->right);
    }

    bool isSymmetricLC(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();
            if (left == nullptr && right == nullptr) {
                continue;
            }
            if (left == nullptr || right == nullptr) {
                return false;
            }
            if (left->val != right->val) {
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = nullptr;
    root->left->right = new TreeNode(3);
    root->right->left = nullptr;
    root->right->right = new TreeNode(3);
    cout << s.isSymmetric(root) << endl;
    return 0;
}
