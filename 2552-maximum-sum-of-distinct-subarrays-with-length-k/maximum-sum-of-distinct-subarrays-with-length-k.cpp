class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        unordered_map<int, int>mp;
        int l=0;
        int r=0;
        long long  maxsum=0;
        while(r<nums.size()){

            //  if(st.find(nums[r])==st.end()){
                sum+=nums[r];
                mp[nums[r]]++;
            // }
            if(r-l+1>k){
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                 l++;
            }

        if(mp.size()==k){
            // cout<<sum<<" ";
            maxsum=max(maxsum, sum);
        }
             r++;
        }
        return maxsum;

    }
};