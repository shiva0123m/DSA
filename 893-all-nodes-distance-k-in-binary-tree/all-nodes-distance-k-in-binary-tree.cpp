/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public :
unordered_map<TreeNode*, TreeNode*> parent; // child -> parent

public:
void findParents(TreeNode* node, TreeNode* par) {
    if (!node) return;
    parent[node] = par;
    findParents(node->left, node);
    findParents(node->right, node);
}

public:
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
    findParents(root, nullptr);
    
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited.insert(target);
    
    int dist = 0;
    while (!q.empty()) {
        int n = q.size();
        if (dist == k) {
            vector<int> res;
            while (!q.empty()) {
                res.push_back(q.front()->val);
                q.pop();
            }
            return res;
        }
        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (node->left && !visited.count(node->left)) {
                q.push(node->left);
                visited.insert(node->left);
            }
            if (node->right && !visited.count(node->right)) {
                q.push(node->right);
                visited.insert(node->right);
            }
            if (parent[node] && !visited.count(parent[node])) {
                q.push(parent[node]);
                visited.insert(parent[node]);
            }
        }
        dist++;
    }
    return {};
}
};