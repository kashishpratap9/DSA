class Solution {
public:

void Subsequences(int i, vector<int>ans, set<vector<int>>&st, vector<int>&nums){
    int n= nums.size();
//    if(ans.size()>=2){
//     result.push_back(ans);
//     return;
//    }

   if( i==n){
    return;
   }

   
   if(ans.size()==0||ans.back()<=nums[i]){
        ans.push_back(nums[i]);
        if(ans.size()>=2){
            st.insert(ans);
        }
        Subsequences(i+1,ans, st, nums);
        ans.pop_back();
    }

      Subsequences(i+1,ans, st, nums);
     



}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>>result;
        vector<int>ans;
        Subsequences(0, ans, st, nums);

        for( auto & i: st){
             result.push_back(i);
        }
        return result;
        
    }
};