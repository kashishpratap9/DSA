class Solution {
public:
void Dijkistra(int src,vector<int>&result, unordered_map<int, vector<pair<int, int>>>&adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({INT_MAX, src});
    result[src]=INT_MAX;

    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int d=p.first;
        int node=p.second;
        for(auto&nbr:adj[node]){
            auto P=nbr;
            int nbrnode=P.first;
            int nbrdis=P.second;
            int mini= min(result[node],nbrdis);
            if( mini<result[nbrnode]){
                result[nbrnode]=mini;
                pq.push({mini, nbrnode});
            }
        }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {

        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto&e: roads){
            int u= e[0];
            int v= e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int>result(n+1,INT_MAX);
        Dijkistra(1, result, adj);
      
        return result[n];



        
    }
};