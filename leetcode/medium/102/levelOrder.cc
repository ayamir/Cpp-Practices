#include <bits/stdc++.h>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr == nullptr) {
                    continue;
                }
                level.push_back(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
            if (!level.empty()) {
                res.push_back(level);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
