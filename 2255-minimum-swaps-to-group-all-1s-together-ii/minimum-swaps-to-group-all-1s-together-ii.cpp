class Solution {
public:
    int minSwaps(vector<int>& nums) {

        //for window size
        int n= nums.size();
        int count_1=0;
        for( int i=0;i<n;i++){
             if( nums[i]==1){
                count_1++;
             }
        }
        
        // for( int i=0;i<2*n;i++){
        //      cout<<new_arr[i]<<' ';
        // }
        int l=0;
        int r=0;
        int maxi=INT_MIN;
        int len=0;
        while(r<2*n){
            if(nums[r%n]==1){
                len++;
            }

            if( r-l+1>count_1){
                    if(nums[l%n]==1 && len>0){
                        len--;
                    }
                l++;
            }

            if( r-l+1==count_1){
                maxi= max(maxi, len);
            }
            r++;

        }

    

        return count_1-maxi;
    }
};