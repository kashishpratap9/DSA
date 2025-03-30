class Solution {
public:

void comboSum(int i, vector<int>&ans, vector<vector<int>>&result, int target, int k, vector<int>&arr){
     if( target==0 && ans.size()==k){
        result.push_back(ans);
        return;
     }
     if( i==arr.size() || target<0){
         return;
     }

      if(arr[i]<=target ){
        ans.push_back(arr[i]);
        comboSum(i+1, ans, result, target-arr[i],k, arr);
        ans.pop_back();
    }

    comboSum(i+1, ans, result, target,k,  arr);
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr(9);
        for( int i=0;i<9;i++){
             arr[i]=i+1;
        }
        vector<int>ans;
         vector<vector<int>>result;
         comboSum(0, ans, result, n, k, arr);
         return result;


        
    }
};