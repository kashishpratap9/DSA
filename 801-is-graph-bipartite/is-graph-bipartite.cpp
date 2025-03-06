class Solution {
public:
bool isPartition(int src, int currcolor, vector<int>&color,unordered_map<int, vector<int>>&adj){
    color[src]=currcolor;
    for( auto nbr: adj[src]){
        if(color[nbr]!=-1 && color[nbr]==color[src]){
            return false;
        }
        if(color[nbr]==-1){
            if(!isPartition(nbr, 1-currcolor, color, adj)){
                return false;
            }
        }
    }
    return true;
}

bool isPartition(int src, vector<int>&color,unordered_map<int, vector<int>>&adj){
  queue<int>q;
  q.push(src);
  color[src]=0;
  while(!q.empty()){
     int node= q.front();
     q.pop();
      for(auto nbr: adj[node]){
        if(color[nbr]!=-1 && color[nbr]==color[node]){
             return false;
        } 
         if( color[nbr]==-1){
            color[nbr]=1-color[node];
            q.push(nbr);
         }
      }
  }

  return true;
}


    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>>adj;
         for(int i=0;i<graph.size();i++){
             for(auto u: graph[i]){
                adj[i].push_back(u);
                adj[u].push_back(i);
             }
         }

         vector<int>color(graph.size(), -1);
         for(int i=0;i<graph.size();i++){
             if(color[i]==-1&& !isPartition(i, color,adj)){
                    return false;
             }
         }

         return true;

        
    }
};