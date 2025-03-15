class Solution {
public:
// int houseRobber(int i,vector<int>&nums, int k, vector<vector<int>>&dp){
//     if( k==0){
//         return 0;
//     }
//     if( i>=nums.size()){
//         return INT_MAX;
//     }
//      if( dp[i][k]!=-1){
//          return dp[i][k];
//      }

//     int skip= houseRobber(i+1, nums, k, dp);
//     int take=max(nums[i], houseRobber(i+2, nums, k-1, dp));

//     return  dp[i][k]=min(skip, take);
// }


bool isPossible( vector<int>&nums, int k , int mid){
     int cn=0;
     int i=0;
     while(i<nums.size()){
        if( nums[i]<=mid){
            cn++;
            i+=2;
        }else{
            i+=1;
        }
     }

     if(cn>=k){
         return true;
     }

     return false;
}
    int minCapability(vector<int>& nums, int k) {
        // vector<vector<int>>dp(nums.size()+1,vector<int>(k+1, -1));
        // return houseRobber(0, nums, k, dp);

        int mini=INT_MAX;
         int maxi=INT_MIN;
          for( int i=0;i<nums.size();i++){
            mini= min(mini, nums[i]);
            maxi= max(maxi, nums[i]);
          }
          int l=mini;
        int r= maxi;
        int ans=-1;
           while( l<=r){
             int mid=l+(r-l)/2;
            if( isPossible( nums, k , mid)){
                ans=mid;
                r= mid-1;
            }else{
                 l= mid+1;
            }
           }
           return ans;
        
    }
};