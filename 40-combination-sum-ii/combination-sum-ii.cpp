class Solution {
public:

void comboSum( int i, vector<int>&ans, vector<vector<int>>&result, int target, vector<int>&arr){
    int n= arr.size();

    if(target==0){
        // sort(ans.begin(), ans.end());
        result.push_back(ans);
        return; 
    }
    if( i>=n || target<0){
         return;
    }
     
  for( int j = i; j<n;j++){
     if( j>i  && arr[j]==arr[j-1]){
        continue;
     }
    if( arr[j]>target){
        break;
    }

    ans.push_back(arr[j]);
    comboSum(j+1,ans, result, target-arr[j], arr);
    ans.pop_back();
  }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>result;
        set<vector<int>>st;
        vector<int>ans;
        comboSum(0, ans, result, target, candidates);
        return  result;
        
    }
};