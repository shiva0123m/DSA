class Solution {
public:
    int maxLen = 0;

    void dfs(TreeNode* node, int leftLen, int rightLen) {
        if (!node) return;
        maxLen = max(maxLen, max(leftLen, rightLen));
        if (node->left)
            dfs(node->left, rightLen + 1, 0); 
        if (node->right)
            dfs(node->right, 0, leftLen + 1); 
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0, 0); 
        return maxLen;
    }
};
