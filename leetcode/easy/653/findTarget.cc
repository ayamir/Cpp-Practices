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
    unordered_set<int> hashSet;

  public:
    bool findTarget(TreeNode *root, int k) {
        inorderTrans(root);
        for (int i = 0, j = inorderTree.size() - 1; i < j;) {
            int sum = inorderTree[i] + inorderTree[j];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }

    void inorderTrans(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        inorderTrans(root->left);
        inorderTree.push_back(root->val);
        inorderTrans(root->right);
    }

    bool findTargetHashRecu(TreeNode *root, int k) {
        if (root == nullptr) {
            return false;
        }
        if (hashSet.count(k - root->val)) {
            return true;
        }
        hashSet.insert(root->val);
        return findTargetHashRecu(root->left, k) ||
               findTargetHashRecu(root->right, k);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
