#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL)
      return NULL;
    if (root == p || root == q)
      return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right)
      return root;
    return left ? left : right;
  }
};

int main(void) {
  TreeNode root(3), l(5), r(1), ll(6), lr(2), rl(0), rr(8), lrl(7), lrr(4);
  root.left = &l;
  root.right = &r;
  l.left = &ll;
  l.right = &lr;
  r.left = &rl;
  r.left = &rr;
  lr.left = &lrl;
  lr.right = &lrr;
  Solution *s = new Solution;
  cout << s->lowestCommonAncestor(&root, &l, &lrr)->val;
  return 0;
}
