class Solution {
public:
void Dijkistra(unordered_map<int, vector<pair<int, double>>>&adj,vector<double>&result,double start_node, int end_node){
    priority_queue<pair<double, int>, vector<pair<double, int>>>pq;
    pq.push({1.0, start_node});
    result[start_node]=1.0;
     while(!pq.empty()){
        auto P= pq.top();
         pq.pop();
         double dis=P.first;
         int node= P.second;
         if( node==end_node){
            break;
         }
         for(auto&nbr: adj[node]){
            auto p= nbr;
            int nbrnode= p.first;
            double nbrdis=p.second;
            // double maxdis= max(dis*nbrdis
            if(result[nbrnode]<dis*nbrdis){
                result[nbrnode]=dis*nbrdis;
                pq.push({dis*nbrdis, nbrnode});
            }

         }

     }


}
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>>adj;
        int i=0;
        for( auto&e: edges){
          int u= e[0];
            int v= e[1];
            adj[u].push_back({v, succProb[i]});
             adj[v].push_back({u, succProb[i]});
            i++;   
        }
        vector<double>result(n, INT_MIN);
        Dijkistra(adj,result,start_node,end_node);
        if( result[end_node]!= INT_MIN){
             return result[end_node];
        }
        return 0.0;
        
    }
};