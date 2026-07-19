



/*
 *  We start of by creating a helper funciton that will check if root, and subtree are exactly the same.
 *  It is basically the is same tree problem in leetcode.
 *  First we check if the subtree is empty, if it is then we return true since that counts as a sub even 
 *  if the root is not empty in that case. If the root is empty though, we would return false.
 *  Then we check if its the same tree, and appply that on the root left, and right side.
 * */ 


bool isSubtree(TreeNode* root, TreeNode* subtree) {
  if (!subtree) {
    return true;
  }
  if (!root) {
    return false;
  }
  if (isSameTree(root,subtree)) {
    return true;
  }
  return isSubtree(root->left,subtree) || isSubtree(root->right,subtree);
}
// Helper function
bool isSameTree(TreeNode* s, TreeNode* t) {
  if (!s && !t) {
    return true;
  }
  if (!s || !t || s->val != t->val) {
    return false;
  }
  return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}
