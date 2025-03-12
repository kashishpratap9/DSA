class Solution {
public:

void dfs(int src,int&cn, vector<bool>&visited,unordered_map<int, vector<int>>&adj){
    visited[src]=true;
    cn++;
    for(auto nbr:adj[src]){
         if(!visited[nbr]){
            dfs(nbr,cn, visited, adj);
         }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
        for( auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n, false);
        vector<long long>result;
        for(int i=0;i<n;i++){
            int countnode=0;
            if(!visited[i]){
                dfs(i, countnode, visited, adj);
                result.push_back(countnode);

            }   

        }

        long long sum=0;
        long long n1= n;
        if(result.size()==1){
             return 0;
        }

        long long totalPairs = (n1 * (n1 - 1)) / 2;
        long long intraComponentPairs = 0;

        for (long long size : result) {
            intraComponentPairs += (size * (size - 1)) / 2;
        }

        return totalPairs - intraComponentPairs;

        // for( int i=0;i<result.size();i++){
        //     long long ans=result[i];
        //     for(int j=i+1;j<result.size();j++){
        //         long long val = ans*result[j];
        //         sum+=val;  
        //     }
        // }


        return sum;


        
    }
};