class Solution {
public:
int maxi=INT_MIN;
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
int dfs( int i, int j, vector<vector<int>>&grid){
    int n= grid.size();
     int m =grid[0].size();

    if( i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
         return 0;
    }

    int val = grid[i][j];
    grid[i][j]=0;
    int maximum=0;
    int d=dfs(i+1, j, grid);
    maximum=max( maximum, d);
    int u=dfs( i-1, j, grid);
     maximum=max( maximum, u);
     int l= dfs( i, j-1, grid);
      maximum=max( maximum, l);
     int r= dfs( i, j+1, grid);
      maximum=max( maximum, r);
    grid[i][j]=val;
      return maximum+ val;


   

}
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxi= INT_MIN;
        for( int i=0;i<grid.size();i++){
             for( int j=0;j<grid[0].size();j++){
                 if(grid[i][j]!=0){
                   maxi= max(maxi,dfs(i, j, grid));
                 }
             }
        }

       if( maxi==INT_MIN){
         return 0;
       }

       return maxi;
        
    }
};