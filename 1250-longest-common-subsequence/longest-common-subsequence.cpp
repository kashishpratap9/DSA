class Solution {
public:
int LCS( int i, int j , string&s1, string&s2,  vector<vector<int>>&dp){
    if( i==s1.size() || j==s2.size()){
        return 0;
    }

    if( dp[i][j] !=-1){
         return dp[i][j];
    }

    if( s1[i]==s2[j]){
        return 1 + LCS(i+1, j+1, s1, s2, dp);
    }

    int fh=LCS(i+1, j, s1, s2, dp);
    int sh= LCS(i, j+1, s1, s2, dp);
    return dp[i][j]=max( fh, sh);
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        return  LCS(0,0,text1, text2, dp);
        
    }
};