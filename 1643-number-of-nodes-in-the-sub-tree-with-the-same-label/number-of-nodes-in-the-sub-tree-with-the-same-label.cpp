class Solution {
public:

void dfs(int src, vector<bool>&visited, vector<int>&count,vector<int>&ans, string&labels, unordered_map<int, vector<int>>&adj){
    visited[src]= true;
    int before=count[labels[src]-'a'];
    count[labels[src]-'a']++;
    for(auto&nbr:adj[src]){
        if(!visited[nbr]){
            dfs(nbr, visited, count,ans, labels, adj);
        }
    }
    int after=count[labels[src]-'a'];
    ans[src]=after-before;


}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>>adj;
        for( auto&e: edges){
            int u= e[0];
            int v= e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>ans(n, 1);
        vector<bool>visited(n, false);
         vector<int>count(26, 0);
        for( int i=0;i<n;i++){
            if(!visited[i]){
               dfs(i, visited,count,ans, labels,adj);
               
            }
        }
        return ans;

        
    }
};