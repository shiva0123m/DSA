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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>>level;
        if (!root) return level;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* it=q.front();
                 q.pop();

                temp.push_back(it->val);
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
               
            }
             level.push_back(temp);
        }
       
        return level;
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<vector<int>>level=levelOrder(root);
        int n=level.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(level[i].back());
        }    
        return ans;
    }
};