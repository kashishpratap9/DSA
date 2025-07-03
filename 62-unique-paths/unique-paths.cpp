class Solution {
public:

int Unique(int i, int j,int m , int n, vector<vector<int>>&dp){
    //base case
    if(i>=m|| j>=n){
        return 0;
    }

    if( i==m-1 && j==n-1){
        return 1;
    }

    if( dp[i][j] !=-1){
         return dp[i][j];
    }

    int d=Unique( i+1, j, m, n, dp);
    int r= Unique( i, j+1, m, n, dp);
    return dp[i][j]=d+r;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return Unique( 0, 0, m, n, dp);
        
    }
};