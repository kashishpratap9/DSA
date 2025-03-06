class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>>adj;
        vector<int>indegree(n, 0);
        vector<int>ans;
        for( auto e: edges){
            int u=e[0];
            int v= e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for( int i=0;i<n;i++){
            // cout<<indegree[i]<<" ";
         if( indegree[i]==0){
            ans.push_back(i);
         }
        }

        return ans.size()==1? ans[0]:-1;
        
    }
};