class Solution {
public:


void Dijkistra(int src, vector<int>&result, unordered_map<int, vector<pair<int, int>>>&adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
    pq.push({0, src});
    result[src]=0;
    while(!pq.empty()){
        auto p= pq.top(); pq.pop();
        int d=p.first;
        int node=p.second;
        for( auto&nbr: adj[node]){
            auto P=nbr;
            int nbrnode= P.first;
            int nbrd=P.second;
            if(result[node]+nbrd<result[nbrnode]){
                result[nbrnode]=result[node]+nbrd;
                pq.push({result[node]+nbrd,nbrnode});
            }
        }
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int, vector<pair<int, int>>>adj;
    int i=0;
            for(auto u:edges){
                if( u!=-1){
                adj[i].push_back({u, 1});
                }
                i++;
        }
        
        if( node1==node2){
             return node1;
        }
        vector<int>result1(edges.size(), INT_MAX);
        vector<int>result2(edges.size(), INT_MAX);
        Dijkistra(node1, result1, adj);
        Dijkistra(node2, result2, adj);
        int mindis = INT_MAX;
        int closestNode = -1;
        for( int i=0;i<edges.size();i++){
            if(result1[i]!=INT_MAX&& result2[i]!=INT_MAX){
                int maxi= max(result1[i],result2[i]);
                cout<<i;
                
                  if(maxi<mindis){
                    mindis=maxi;
                    closestNode=i;
                }
                else if(maxi==mindis && i< closestNode){
                     closestNode=i;
                }
            }

        }

        return  closestNode;
    
   

    }
};