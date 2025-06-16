class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n = nums.size();
        int maxlen=0;
         while( r<n){
             if(nums[r]==0 ){
                k--;
            }
           
                 while(k<0){
                     if(nums[l]==0){
                        k++;
                     }
                     l++;
                 }
            
           
            maxlen=max( maxlen, r-l+1);
             r++;
         }
         return maxlen;

        
    }
};