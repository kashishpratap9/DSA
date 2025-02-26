class Solution {
public:

// void Maxsum(int i,ector<int>& nums, int&sum, int&maxi ){
//     //base case
   

    int maxAbsoluteSum(vector<int>& nums) {
        //using kadanes algorithm

      int currsum=nums[0];
      int maxsum=nums[0];
       for( int i=1;i<nums.size();i++){
        if( nums[i] > currsum+nums[i]){
            currsum=nums[i];
        }else{
            currsum= currsum+nums[i];

        }
         maxsum= max( maxsum, currsum);
       }

     currsum=nums[0];
      int minsum=nums[0];
       for( int i=1;i<nums.size();i++){
        if( nums[i] < currsum+nums[i]){
            currsum=nums[i];
        }else{
            currsum= currsum+nums[i];

        }
         minsum= min( minsum, currsum);
       }
    //    cout<<maxsum<<" "<<minsum;

       return max( abs(maxsum), abs(minsum));
        
    }
};