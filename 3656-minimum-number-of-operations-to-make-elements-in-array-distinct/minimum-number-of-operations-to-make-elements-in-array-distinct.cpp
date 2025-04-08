class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int>mp;
         for( int i=0;i<nums.size();i++){
             mp[nums[i]]++;
         }

         if( mp.size()==nums.size()){
             return 0;
         }
         int i=3;
         int count=1;
         while(i<nums.size()){
            unordered_set<int>st(nums.begin()+i, nums.end());
            if( st.size()==nums.size()-i){
               break;
            }
            count++;
            i+=3;
         }
         return count;



        
    }
};