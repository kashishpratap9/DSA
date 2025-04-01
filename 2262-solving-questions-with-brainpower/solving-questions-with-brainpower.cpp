class Solution {
public:

long long maxPoints(int i, vector<vector<int>>& questions, vector<long long >&dp){
    int n = questions.size();
     if( i>=n){
         return 0;
     }
     if( dp[i] != -1){
        return dp[i];
     }
     long long  notake=maxPoints(i+1, questions, dp);
     long long  take= questions[i][0] + maxPoints(i+questions[i][1]+1, questions, dp);
    return dp[i]=max( take, notake);

}
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(), -1);
        return maxPoints(0, questions, dp);

        
        
    }
};