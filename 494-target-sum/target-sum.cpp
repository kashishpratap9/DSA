class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //it is similar to problem that has count the no of subsets that is equal to a difference k 
        // because we just need to divide our array in two subset one is of positive elements and another is of negative elements 
        //s1-s2= target
        //s1( all positive) s2( all negative)
        //s1+s2= sum
        //s1= (target +sum)/2;

        int sum=0;
        for( int i=0;i<nums.size();i++){
             sum+=nums[i];
        }

        if( (target + sum)%2!=0 || sum <abs(target) ){
             return 0;
        }
        int s1= (target+sum)/2;

        vector<vector<int>>dp( nums.size()+1, vector<int>(s1+1 ,0));
        for( int i=0;i<=nums.size(); i++){
            dp[i][0]=1;
        }

        for( int i=1;i<=nums.size();i++){
             for( int j=0;j<=s1;j++){
                int exc= dp[i-1][j];
                int  inc= 0;
                if( nums[i-1]<=j){
                    inc = dp[i-1][j-nums[i-1]];
                }
                dp[i][j]= inc+exc;

             }
        }

        return dp[nums.size()][s1];

        
    }
};