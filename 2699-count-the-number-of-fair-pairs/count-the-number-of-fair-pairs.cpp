class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count=0;
      
        //  for( int i=0;i<nums.size();i++){
        //      for( int j=i+1;j<nums.size();j++){
        //        int val = nums[i]+ nums[j];
        //         if(val>=lower && val<=upper){
        //             count++;

                    
        //         }
        //      }
        //  }

        //  return count;
         long long ans = 0;
            sort(nums.begin(), nums.end());
            for (int i = 0; i + 1 < nums.size(); i++) {
                int minReq = lower - nums[i], maxReq = upper - nums[i];
                auto high = upper_bound(nums.begin() + i + 1, nums.end(), maxReq);
                auto low = lower_bound(nums.begin() + i + 1, nums.end(), minReq);
                ans += (high - low);
            }
            return ans;
    }
};