class Solution {
public:

int  Satisfy( int i, int time,vector<int>& satisfaction, vector<vector<int>>&dp){
    if( i>=satisfaction.size()){
        return 0;
    }
    if( dp[i][ time]!=-1){ return dp[i][time];}

    int exc= Satisfy(i+1,time,satisfaction,dp);
    int inc= satisfaction[i]* time+Satisfy(i+1,time+1,satisfaction,dp);

    return dp[i][time]=max( inc, exc);
}
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int time=1;
        int value=0;

        return Satisfy(0, time, satisfaction, dp);

        
    }
};