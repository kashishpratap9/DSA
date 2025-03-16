class Solution {
public:
bool isValid( vector<int>&nums, int mid){
    int n = nums.size();
    vector<long long>temp(nums.begin(), nums.end());
    for( int i=0;i<temp.size()-1;i++){
         if( temp[i]>mid){
           return false;
         }
        long long  buffer=mid-temp[i];
        temp[i+1]= temp[i+1]-buffer;
    }
    return temp[n-1]<=mid;
}
    int minimizeArrayValue(vector<int>& nums) {
        int maxi= 0;
        for( int i=0;i<nums.size();i++){
            maxi=max( maxi, nums[i]);   
        }
        int l=1;
         int r=maxi;
         int ans =0;
          while( l<=r){
             int mid= l+(r-l)/2;
            if(isValid( nums, mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
          }
          return ans;
    }
};