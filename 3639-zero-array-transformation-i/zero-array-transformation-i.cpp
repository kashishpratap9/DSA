class Solution {
public:

bool isZero(vector<int>&nums){
    for( int i=0;i<nums.size();i++){
         if( nums[i]>0){
            return false;
         }
    }
    return true;
}
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int>diff(nums.size()+1, 0);
        for( auto q: queries){
            int l=q[0];
            int r= q[1];
    
          diff[l]-=1;
            if(r+1<nums.size()){
                diff[r+1]+=1;
            }

     }

        int val=0;

        for(int i=0;i<nums.size();i++){
            val+=diff[i]; 
            nums[i]+=val;
         }


    return isZero(nums); // Check if nums is a zero array




        // return false;
        
    }
};