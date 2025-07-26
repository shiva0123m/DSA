class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }

    void collectLeaves(TreeNode* root, vector<int>& leaves) {
        if (root == nullptr) return;

        if (isLeaf(root)) {
            leaves.push_back(root->val);
        } else {
            collectLeaves(root->left, leaves);
            collectLeaves(root->right, leaves);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;

        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }
};
