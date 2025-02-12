class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

       sort(nums.begin(), nums.end());
       int moves=0;
        for( int i=1;i<nums.size();i++){
             if( nums[i-1]==nums[i]){
                nums[i]= nums[i]+1;
                moves++;
             }else if( nums[i-1]> nums[i]){
                int val= nums[i];
                nums[i]= nums[i-1]+1;
                moves+=(nums[i]-val);
             }
        }

        return moves;

        
    }
};