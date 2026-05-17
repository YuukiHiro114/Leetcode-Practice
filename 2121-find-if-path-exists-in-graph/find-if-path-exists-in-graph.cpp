class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> viz(n,0);//用container去註記每個vertices是不是有被走訪過
        for(auto&e:edges){ //使用BFS或DFS要建立Adjacent List
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(source);//先走訪source
        viz[source]=1;
        while(!q.empty()){//queue不為空就執行while loop
            int v=q.front();
            q.pop(); //將queue的前端設為v並將它pop出來
            if(v==destination) return 1;
            for(int u:adj[v]){ //不是true就進入v的adjacent list，透過for loop一個個去看他的adjacent vertices
                if(!viz[u]){ //沒有走訪過，我們就將這個vertices u將它push進來，當然也要註記它已經走訪過了
                    q.push(u);
                    viz[u]=1;
                }
            }

        }
        return 0; //整個while loop走完，return false
    }

};