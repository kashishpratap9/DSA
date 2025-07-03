class Solution {
public:
int minTotal( int i, int j , vector<vector<int>>&grid, vector<vector<int>>&dp){
    int n = grid.size();
    if( i>=n  || j>i){
        return INT_MAX;
    }
    
//base condition 
     if(i==n-1){
        return grid[i][j];
     }

     if( dp[i][j] != -1){
         return dp[i][j];
     }

     int samecol= minTotal( i+1, j , grid, dp);
     int diffcol= minTotal( i+1, j+1, grid, dp);
      return dp[i][j]= grid[i][j] + min(samecol , diffcol);

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp;
         for( int i=0;i<n;i++){
            vector<int>ans;
            for( int j=0 ;j<=i;j++){
                ans.push_back(-1);
            }
            dp.push_back(ans);
         }
        return minTotal( 0, 0, triangle, dp);
        
    }
};