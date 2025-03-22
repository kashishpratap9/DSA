class Solution {
public:
void dfs(int src, int&cn, int&ecn,vector<bool>&visited, unordered_map<int, vector<int>>&adj){
    visited[src]=true;
    cn++;
     for( auto nbr:adj[src]){
        ecn++;
        if(!visited[nbr]){
            dfs(nbr, cn, ecn,visited, adj);
        }
     }
}


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
        for( auto e: edges){
             int u=e[0];
             int v=e[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        
        vector<bool>visited(n, false);
        int count=0;
        int completecount=0;
         for( int i=0;i<n;i++){
            int countnode=0;
            int edgecount=0;
             if(!visited[i]){
               dfs(i, countnode, edgecount,visited, adj);
               edgecount=edgecount/2;
               int actual = countnode* (countnode-1)/2;
               if( actual==edgecount){
                completecount++;
               }
              
             }
         }
         return completecount;
    }
};