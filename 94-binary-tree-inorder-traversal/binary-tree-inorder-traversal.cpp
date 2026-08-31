/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findInOrderTraversal(TreeNode* root,vector<int>&inOrder)
    {
        if(root==NULL)
        {
            return ;
        }
        findInOrderTraversal(root->left,inOrder);
        inOrder.push_back(root->val);
        findInOrderTraversal(root->right,inOrder);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>inOrder;

        findInOrderTraversal(root,inOrder);
        return inOrder;
    }
};