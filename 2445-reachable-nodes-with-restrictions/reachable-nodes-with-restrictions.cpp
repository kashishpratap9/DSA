class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int , vector<int>>adj;
         for( auto e: edges){
            int u= e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
         }
         vector<bool>visited(n, false);
         unordered_set<int>st(restricted.begin(), restricted.end());
        // for( int i=0;i<restricted.size();i++){
        //     visited[restricted[i]]=true;
        // }

       queue<int>q;
        q.push(0);
        visited[0]=true;
        int cn=0;
         while(!q.empty()){
            int node= q.front();
            cn++;
             q.pop();

             for(auto nbr: adj[node]){
                if(!visited[nbr] &&  st.find(nbr)==st.end()){
                    visited[nbr]=true;
                    q.push(nbr);
                }
             }

         }

         return cn;

    }
};