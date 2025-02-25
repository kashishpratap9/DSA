class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort( nums.begin(), nums.end());
        vector<int>ans(nums.size());
        unordered_set<int>st;
        ans[0]=nums[0];
        st.insert(ans[0]);
        int moves=0;
         for( int i=1;i<nums.size();i++){
            if(ans[i-1]==nums[i]||st.find(nums[i])!=st.end()){
                ans[i]= ans[i-1]+1;
                st.insert(ans[i]);
                moves+=ans[i]-nums[i];
            }else{
                ans[i]=nums[i];
                st.insert(ans[i]);
            }
         }

         for( int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
         }
         return moves;
        
    }
};