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
    pair<bool,int>checkTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return {true,0};
        }
        pair<bool,int> left=checkTree(root->left);
        pair<bool,int> right=checkTree(root->right);

        bool checkHeight=abs(left.second-right.second)<=1;
        if(!left.first || !right.first || !checkHeight)
        {
            return {false,-1};
        }
        return {true,1+max(left.second,right.second)};
    }
    bool isBalanced(TreeNode* root) 
    {
        pair<bool,int>ans;
        ans=checkTree(root);
        return ans.first;
    }
};