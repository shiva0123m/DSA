class Solution {
public:
    int findHeight(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = findHeight(root->left);
        int right = findHeight(root->right);

        return max(left, right) + 1;
    }

    int maxDepth(TreeNode* root) 
    {
        return findHeight(root); 
    }
};
