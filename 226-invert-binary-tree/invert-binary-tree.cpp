class Solution {
public:
    TreeNode* Invert(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* left = Invert(root->left);
        TreeNode* right = Invert(root->right);

        root->left = right;
        root->right = left;

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return Invert(root);
    }
};
