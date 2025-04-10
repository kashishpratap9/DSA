class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int minlen=INT_MAX;
        // for( int i=0;i<nums.size();i++){
        //     int sum=0;
        //      for( int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //          if( sum>=target){
        //             minlen= min(minlen, j-i+1);
        //             break;
        //          }


        //      }
        // }
        // return minlen==INT_MAX?0: minlen;
        int l=0;
        int r=0;
        int sum=0;
        int minlen= INT_MAX;
         while(r<nums.size()){
            sum+=nums[r];
             while(sum>=target){
                minlen=min(minlen, r-l+1);
                sum-=nums[l];
                l++;
             }
             r++;
         }
         return minlen==INT_MAX?0: minlen;
        
        
    }
};