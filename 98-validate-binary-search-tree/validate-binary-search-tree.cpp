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
public :
    struct tripletReturn
    {
        bool isValid;
        long long min;
        long long max;
    };
public:
    tripletReturn getValidity(TreeNode* root)
    {
        if(root==nullptr)
        {
            return {true,LLONG_MAX,LLONG_MIN};
        }
        if (root->left == nullptr && root->right == nullptr) 
        {
            return {true,(long long) root->val, (long long)root->val};
        }

        tripletReturn left=getValidity(root->left);
        tripletReturn right=getValidity(root->right);

        int minValue=min((long long)root->val,left.min);
        int maxValue=max((long long)root->val,right.max);

        if(!left.isValid || !right.isValid || root->val<=left.max || root->val>=right.min)
        {
            return {false,0,0};
        }

        return {true,minValue,maxValue};
    }
    bool isValidBST(TreeNode* root) 
    {
           tripletReturn t=getValidity(root);
           return t.isValid; 
    }
};