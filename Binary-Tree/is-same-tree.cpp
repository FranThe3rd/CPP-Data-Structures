/*
 * We recursively compare both trees node by node.
 * Base Cases:
 * 1. If both nodes are nullptr:
 *      - We've reached the end of both branches at the same time.
 *      - They match, so return true.
 * 2. If one node is nullptr OR their values are different:
 *      - One tree has a node while the other doesn't,
 *        or the values don't match.
 *      - The trees cannot be identical, so return false.
 * Since the current nodes are equal, we must verify that:
 *   - the left subtrees are identical, AND
 *   - the right subtrees are identical.
 * We use && because BOTH sides must match for the trees
 * to be considered the same.
 * Time Complexity: O(n)
 *   - Every node is visited exactly once.
 * Space Complexity: O(h)
 *   - h is the height of the tree.
 *   - Recursive calls are stored on the call stack.
 *   - Worst case: O(n) for a completely skewed tree.
 *   - Best/Average: O(log n) for a balanced tree.
 */

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
