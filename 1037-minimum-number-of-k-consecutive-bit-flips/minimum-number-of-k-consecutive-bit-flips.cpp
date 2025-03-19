class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int fc=0;
        int result=0;
        vector<bool>isflip(nums.size(), false);
        for( int i=0;i<nums.size();i++){
            //hum bahar nkal gye h uss patticular subarray se

            if(i>=k && isflip[i-k]==true){
                    fc--;
            }

            if(fc%2==nums[i]){
                //we have to flip
                if(i+k>nums.size()){
                     return -1;
                }
                fc++;
                isflip[i]= true;
                result++;

            }

        }

        return result;
        
        
    }
};