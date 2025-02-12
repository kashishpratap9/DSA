class Solution {
public:


int digitsum(int num){
    int dsum=0;
    while( num!=0){
         int digit = num%10;
         dsum+=digit;
         num= num/10;    
    }
    return dsum;

}
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int>mp;
        int sum=0;
        int maxi=-1;
        for( int i=0;i<nums.size();i++){
             int val= digitsum(nums[i]);
             if(mp.find(val)!= mp.end()){
                sum= mp[val]+ nums[i];
                maxi= max( maxi, sum);
                if(mp[val]<nums[i]){
                     mp[val]=nums[i];
                }
             }else{
                mp[val]=nums[i];
             }
        }

       

        return maxi;


        
    }
};