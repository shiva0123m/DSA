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
class Solution 
{
    public:
        void findAllPaths(TreeNode* root,vector<string>&ans,string curr)
        {
            if(root==NULL)
            {
                return;
            }

            string newCurr;
            if(curr=="")
            {
                newCurr=to_string(root->val);
            }
            else
            {
                newCurr=curr+"->"+to_string(root->val);
            }

            if(root->left==NULL && root->right==NULL)
            {
                ans.push_back(newCurr);
                return;
            }
            findAllPaths(root->left,ans,newCurr);
            findAllPaths(root->right,ans,newCurr); 
        }
        vector<string> binaryTreePaths(TreeNode* root) 
        {
            vector<string>ans;
            string curr;

            findAllPaths(root,ans,curr);
            return ans;
        }
};