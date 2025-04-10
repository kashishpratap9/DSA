class Solution {
public:

int CompleteSubarray( vector<int>&nums, int k){
    if( k<0){
         return 0;
    }
    int l=0;
    int r=0;
    int count=0;
    unordered_map<int, int>mp;
    while( r<nums.size()){
        mp[nums[r]]++;
        while( mp.size()>k){
            mp[nums[l]]--;
             if( mp[nums[l]]==0){
                 mp.erase(nums[l]);
             }
             l++;
        }
        if( mp.size()<=k){
             count+=(r-l+1);
        }
        r++;
    }
    return count;

}
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
         for( int i=0;i<nums.size();i++){
             st.insert(nums[i]);
         }
         int k= st.size();
        return CompleteSubarray(nums, k) - CompleteSubarray(nums, k-1);

        
    }
};