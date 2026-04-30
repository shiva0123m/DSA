class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // If the tree is empty, it's symmetric
        if (root == NULL) {
            return true;
        }
        
        // Start the recursive comparison between left and right subtrees
        return isSymmetricHelper(root->left, root->right);
    }

private:
    // Helper function to compare two subtrees
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        // Both are NULL, so they are symmetric
        if (left == NULL && right == NULL) {
            return true;
        }

        // One is NULL and the other is not, not symmetric
        if (left == NULL || right == NULL) {
            return false;
        }

        // Check if the current nodes are equal and the left subtree is a mirror of the right subtree
        return (left->val == right->val) &&
               isSymmetricHelper(left->left, right->right) &&  // Left of left subtree with right of right subtree
               isSymmetricHelper(left->right, right->left);   // Right of left subtree with left of right subtree
    }
};