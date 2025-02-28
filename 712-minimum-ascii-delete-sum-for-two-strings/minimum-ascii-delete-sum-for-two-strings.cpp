class Solution {
public:
int deletesum(int i , int j, string&s1, string&s2, vector<vector<int>>&dp){
    int n= s1.size();
     int m=s2.size();
     if( i==n){
        int sum=0;
        for(int k=j;k<s2.size();k++){
            sum+=(int)s2[k];
        }
        return sum;

     }
     if( j==m){
          int sum=0;
        for(int k=i;k<s1.size();k++){
            sum+=(int)s1[k];
        }
        return sum;
     }

     if( dp[i][j] !=-1){
        return dp[i][j];
     }

     if( s1[i]==s2[j]){
        return deletesum(i+1, j+1, s1, s2, dp);
     }

     return dp[i][j]=min((int)s1[i] + deletesum(i+1, j, s1,s2, dp), (int)s2[j] + deletesum(i, j+1, s1,s2, dp));

}
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size(), vector<int>(s2.size(), -1));
        
       return  deletesum(0, 0, s1, s2, dp);

    }
};