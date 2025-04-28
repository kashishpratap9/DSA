class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // long long count=0;
        // for(int i=0;i<nums.size();i++){
        //      long long sum=0;
        //      int len=0;
        //      for( int j=i;j<nums.size();j++){
        //             sum+=nums[j];
        //             len=j-i+1;
        //             long long val = sum* len;
        //             if( val >=k){
        //                 break;
        //             }else{
        //                 count++;
        //             }

        //      }
        // }
        // return count;
        int n = nums.size();
        int l=0;
         int r=0;
        // sort( nums.begin(), nums.end());
        long long  count=0;
        long long sum=0;
        while(r<n){
            sum+=nums[r];
            long long val = sum*( r-l+1);
            while(val>=k){
                sum-=nums[l];
                l++;
               val=sum*(r-l+1);
               
            }

            if( val < k){
                // cout<<val<<" ";
                count+=(r-l+1);
            }
             r++;

        }
         return  count;
    

        
    }
};