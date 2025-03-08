class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        int count_1=0;
        for( int i=0;i<n;i++){
             if( nums[i]==1){
                count_1++;
             }
        }
        vector<int>new_arr(2*n);
        for( int i=0;i<2*n;i++){
            new_arr[i]=nums[i%n];
        }

        // for( int i=0;i<2*n;i++){
        //      cout<<new_arr[i]<<' ';
        // }
        int l=0;
        int r=0;
        int maxi=INT_MIN;
        int len=0;
        while(r<2*n){
            if(new_arr[r]==1){
                len++;
            }

            if( r-l+1>count_1){
                    if(new_arr[l]==1 && len>0){
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