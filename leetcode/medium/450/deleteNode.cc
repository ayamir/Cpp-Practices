#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr)
            return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            auto node = root->right;
            while (node->left != nullptr)
                node = node->left;
            node->left = root->left;
            root = root->right;
        }
        return root;
    }

    void iter(TreeNode *root) {
        if (root == nullptr)
            return;
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                if (curr == nullptr)
                    continue;
                level.push_back(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
            if (!level.empty()) {
                ret.push_back(level);
            }
        }
        for (const auto &vec : ret) {
            for (const auto &e : vec) {
                cout << e << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *root =
        new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)),
                     new TreeNode(6, nullptr, new TreeNode(7)));

    auto node = s.deleteNode(root, 5);
    s.iter(node);
    return 0;
}
