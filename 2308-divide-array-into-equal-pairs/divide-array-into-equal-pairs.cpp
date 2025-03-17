class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int total_pairs=n/2;
        for( int i=0;i<n-1;i++){
             if(nums[i]!=nums[i+1]){
                return false;

             }
             i++;
        }

        return true;



        
    }
};