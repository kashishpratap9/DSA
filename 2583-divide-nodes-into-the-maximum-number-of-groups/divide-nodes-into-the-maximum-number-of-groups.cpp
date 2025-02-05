class Solution {
public:

bool dfs(int src, vector<int>&color,int currcolor,unordered_map<int, vector<int>>&adj){
    color[src]=currcolor;
    for(auto& nbr: adj[src]){
        if(color[src]==color[nbr]){
             return false;
        }

        if( color[nbr]==-1){
             if(dfs(nbr, color,1-currcolor, adj)==false){
                return false;
             }
        }
    }

    return true;
}

int bfs( unordered_map<int, vector<int>>&adj,int i, int n){
     vector<int>visited(n, false);
      queue<int>q;
      int l=0;
    
    q.push(i);
     visited[i]= true;
    while(!q.empty()){
    int size= q.size();
         for( int i=0;i<size;i++){
           int front= q.front();
             q.pop();
                for( auto& nbr:adj[front]){
                  if(!visited[nbr]){
                      q.push(nbr);
                        visited[nbr]= true;
                          }
                  }

              }    
              l++;
    } 

    return l;       
     
}

int getMax( unordered_map<int, vector<int>>&adj, vector<int>&visited1,  vector<int>&levels, int src){
    int val = levels[src];
    visited1[src]= true;
    for(auto&nbr: adj[src]){
        if(!visited1[nbr]){
            val = max( val, getMax(adj, visited1, levels, nbr));
        }
    }

    return val;

}
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
   
        for(auto&e: edges){
            int u=e[0]-1;//converting it into the zero based indexing
            int v= e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n, -1);
        for( int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i, color, 0, adj)==false){
                    return -1;
                }
            }
        }


  vector<int>levels(n, 0);
     vector<int>visited(n, false);
           for(int i=0;i<n;i++){
            levels[i]=bfs(adj, i, n);
        }

        
     vector<int>visited1(n, false);
     int maxi=0;
     for(int i=0;i<n;i++){
         if(!visited1[i]){
            maxi+=getMax( adj, visited1, levels,i);

         }
     }

        


        return maxi;



        
    }
};