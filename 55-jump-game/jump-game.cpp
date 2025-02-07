class Solution {
public:
bool Jump(int i, vector<int>&nums, vector<int>&dp){
    int n = nums.size();
     if( i==n-1){
        return true;
     }

     if( dp[i] != -1){
         return dp[i];
     }


   bool take= false;
   for(int j=1;j<=nums[i];j++){
        if(Jump(i+ j, nums, dp)){
            take= true;
            break;
        }
   }
   

//    bool nottake= Jump(i+1, nums, dp);
   return  dp[i]=take;


}
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1, -1);
        return Jump(0, nums, dp);
        
    }
};