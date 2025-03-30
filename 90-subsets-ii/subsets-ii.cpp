class Solution {
public:

void Subsets(int i, vector<int>&ans,set<vector<int>>&st, vector<int>&nums){
    int n= nums.size();
    if( i==n){
      st.insert(ans);
         return;
    }
    ans.push_back(nums[i]);
    Subsets(i+1, ans,st, nums);
    ans.pop_back();
    Subsets(i+1, ans,st, nums);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        vector<vector<int>>result;
        set<vector<int>>st;
        Subsets(0, ans, st, nums);
        for( auto i:st){
            result.push_back(i);
        }
        // sort(result.begin(), result.end());
        return result;
        
    }
};