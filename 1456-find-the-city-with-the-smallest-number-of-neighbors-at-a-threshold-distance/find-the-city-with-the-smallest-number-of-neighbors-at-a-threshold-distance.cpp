class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>>adj;
          vector<vector<int>>grid(n, vector<int>(n,INT_MAX));

          for( int i=0;i<n;i++){
             for( int j=0;j<n;j++){
                 if(i==j){
                     grid[i][j]=0;
                 }
             }
          }
        for(auto e:edges){
            int u=e[0];
            int v= e[1];
            int w=e[2];
            grid[u][v]=w;  
            grid[v][u]=w;  
        }

      for( int k=0;k<n;k++){
        for( int i=0;i<n;i++){
             for( int j=0;j<n;j++){
                if( grid[i][k]!=INT_MAX && grid[k][j]!= INT_MAX){
                    grid[i][j]= min(grid[i][j], grid[i][k] + grid[k][j]);
                }
             }
        }
      }
        
        for( int i=0;i<n;i++){
            for( int j=0;j<n;j++){
                 if( grid[i][j]> distanceThreshold){
                    grid[i][j]=-1;
                 }
            }
        }

        int minicount=INT_MAX;
        int city;

         for( int i=0;i<n;i++){
            int count=0;
            for( int j=0;j<n;j++){
               if( i!=j  && grid[i][j]!=-1){
                    count++;
               }
            }
            // cout<<count;
            if(minicount>=count){
                // cout<<count;
               minicount=count;
               city=i;
            }
        }
       return city;
        
    }
};