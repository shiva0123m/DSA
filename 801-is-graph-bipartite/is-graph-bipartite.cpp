class Solution {
public:
    bool bfs(int node,vector<vector<int>>& graph,vector<int>&visited,vector<int>&color)
    {
        queue<int>q;
        q.push(node);
        color[node]=0;
        visited[node]=1;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            for(auto it : graph[node])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[node]==color[it])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int>visited(graph.size(),0);
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(!visited[i])
            {
                if(!bfs(i,graph,visited,color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};