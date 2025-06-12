class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi= INT_MIN;
        int n = nums.size()-1;
    
        for( int i=1;i<nums.size();i++){
            int diff=abs(nums[i-1]-nums[i]);
            maxi= max( maxi, diff);

        }
        maxi = max(maxi,abs(nums[0]-nums[n]));
        return maxi;
        

        
    }
};