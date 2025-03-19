class Solution {
public:
bool isone( vector<int>&nums){
     for( int i=0;i<nums.size();i++){
         if( nums[i]==0){
            return false;
         }
     }

     return true;
}
    int minOperations(vector<int>& nums) {
        //brute force i s simply find the zero and then just convert it into 1 of length 3
       int i=0;
       int count=0;
       int n= nums.size();
       
    while(i<nums.size()){
        if(nums[i]==0&&i+1<n && i+2<n){
            nums[i]=1-nums[i];
            nums[i+1]=1-nums[i+1];
            nums[i+2]=1-nums[i+2];
            count++;
        }
        i++;
    }
   if(isone(nums)){
            return count;
        }

        return -1;
        
    }
};