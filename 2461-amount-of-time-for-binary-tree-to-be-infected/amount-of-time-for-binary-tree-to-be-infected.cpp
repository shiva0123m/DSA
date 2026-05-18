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
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;
        
        // Step 1: Map each node to its parent
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = nullptr;
        mapParents(root, nullptr, start, parentMap, startNode);
        
        // Step 2: BFS from startNode to calculate time
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);
        int time = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            bool infectedNewNode = false;
            
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Check left child
                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                    infectedNewNode = true;
                }
                
                // Check right child
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                    infectedNewNode = true;
                }
                
                // Check parent
                TreeNode* par = parentMap[node];
                if (par && visited.find(par) == visited.end()) {
                    visited.insert(par);
                    q.push(par);
                    infectedNewNode = true;
                }
            }
            
            if (infectedNewNode) time++;
        }
        
        return time;
    }
    
private:
    void mapParents(TreeNode* node, TreeNode* parent, int start,
                    unordered_map<TreeNode*, TreeNode*>& parentMap,
                    TreeNode*& startNode) {
        if (!node) return;
        
        parentMap[node] = parent;
        if (node->val == start) startNode = node;
        
        mapParents(node->left, node, start, parentMap, startNode);
        mapParents(node->right, node, start, parentMap, startNode);
    }
};