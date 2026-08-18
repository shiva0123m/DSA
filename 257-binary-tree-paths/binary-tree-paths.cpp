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


//  1.run preorder on 
//  2.Once traversal hit leaf node store path
//  3.undo /remove the element while back track(base case root==NULL)
//  4. Return the vector string 
//  edge case :
class Solution 
{
    public:
        void preorder(TreeNode* node,string curr,vector<string>&ans)
        {
            if(node==NULL)
            {
                return;
            }
            if(curr.empty())
            {
                curr=to_string(node->val);
            }
            else
            {
                curr+="->"+to_string(node->val);
            }

            if(node->left==NULL && node->right==NULL)
            {
                ans.push_back(curr);
                return;
            }
            preorder(node->left,curr,ans);
            preorder(node->right,curr,ans); 
        }
        vector<string> binaryTreePaths(TreeNode* root) 
        {
           vector<string>ans;
           preorder(root,"",ans); 
           return ans;
        }
};