class Solution {
public:


void  Dijkistra(unordered_map<int, vector<pair<int, int>>>&adj, vector<int>&result, int k , int n){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, k});
    result[k]=0;
    
    while(!pq.empty()){
        auto P = pq.top();
        pq.pop();
        int d=P.first;
        int node=P.second;
        for( auto& nbr: adj[node]){
            auto p=nbr;
            int nbrd=p.second;
            int nbrnode= p.first;
            if(result[node] + nbrd < result[nbrnode]){
                result[nbrnode]=result[node]+ nbrd;
                pq.push({nbrd, nbrnode});
            }
        }
    
    }

}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>>adj;
        for( auto&e: times){
            int u=e[0];
            int v= e[1];
            int w= e[2];
            adj[u].push_back({v, w});
        }
        vector<int>result(n+1, INT_MAX);
         Dijkistra(adj, result, k, n);
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi= max(maxi, result[i]);
        }
if( maxi==INT_MAX){
     return -1;
}

  

        return maxi;




        
    }
};