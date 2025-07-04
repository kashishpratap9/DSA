class Solution {
public:
    int numDistinct(string s, string t) {

        //we have to find the occurence of t in s like how many times it occur 
        int n=s.size();
        int m = t.size();
        vector<vector<unsigned long long>>dp(n+1, vector<unsigned long long>(m+1, 0));
        dp[0][0]=1;
        for( int i=1;i<=n;i++){
            //means there will be nothing left in j to match it is empty
            dp[i][0]=1;
        }
        
        for( int i=1;i<=n;i++){
             for( int j=1;j<=m;j++){
                if( s[i-1]==t[j-1]){
                    //agar dono eual h to do case ho skte h either hume usko lele jo match kr rha h ya phir either  we choose to proceed withe next section
                    dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]= dp[i-1][j];
                }
             }
        }

        return dp[n][m];
        
    }
};