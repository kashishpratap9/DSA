class Solution {
public:
void comboSum(int i, vector<int>&ans, vector<vector<int>>&result, int target, vector<int>&arr){
    int n= arr.size();
    if(i==n||target<0){
        return;
    }

    if( target==0){
       if( result.empty()){
        result.push_back( ans);
       }else if( result.back() != ans){
        result.push_back( ans);
       }
    }
    if(arr[i]<=target){
        ans.push_back(arr[i]);
        comboSum(i, ans, result, target-arr[i], arr);
        ans.pop_back();
    }

    comboSum(i+1, ans, result, target, arr);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        // unordered_set
        vector<int>ans;
        
     comboSum(0,  ans, result, target, candidates);
     return result;

        
    }
};