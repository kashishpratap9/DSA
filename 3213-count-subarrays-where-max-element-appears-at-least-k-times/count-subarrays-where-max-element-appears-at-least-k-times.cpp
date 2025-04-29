class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int n= nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi, nums[i]);
        }
       for( int  i=0;i<n;i++){
         if(nums[i]==maxi){
            nums[i]=1;
         }else{
            nums[i]=0;
         }
       }

       int l=0;
        int r=0;
        int maxc=0;
        long long  count=0;
        while( r<n){
            if( nums[r]==1){
                 maxc++;
            }


            while( maxc>=k){
                count+=(n-r);//baad wale sare
                cout<<count;

                if( nums[l]==1){
                    maxc--;
                }
                l++; 
            }

            
            r++;

        }
 
        return count;

       
        
    }
};