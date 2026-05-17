class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>&adj, vector<bool>&vis,vector<int>&color){
        color[node] = col;
        vis[node] = true;

        for(auto child: adj[node]){
            if(!vis[child]){
                if(dfs(child, 3 -col,adj,vis,color)){
                    return true;
                }
            }
            if(color[node]==color[child]){
                return true;
            }
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& a) {
        vector<vector<int>>adj(n+1);
        vector<int> color(n+1, 0);
        vector<bool>vis(n+1,false);

        for(auto it:a){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(dfs(i,1,adj,vis,color)==true){
                    return false;
                }
            }
        }
        return true;
    }
};