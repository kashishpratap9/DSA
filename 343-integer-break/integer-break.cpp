class Solution {
public:
void Break(int i, int n, vector<int>&ans, vector<int>&result, int&maxi){
    if(n==0){
        int val=1;
        for( int i=0;i<ans.size();i++){
           val*=ans[i];
        }
        maxi= max( maxi, val);
        return; 
    }

    if( i==result.size()||n <0){
         return;
    }

    //include
   if(result[i]<= n){
    ans.push_back(result[i]);
    Break(i, n-result[i], ans, result, maxi);
    ans.pop_back();
   }

    Break(i+1, n, ans, result, maxi);

}
    int integerBreak(int n) {

        vector<int>result;
        for( int i=1;i<n;i++){
            result.push_back(i);
        }

        vector<int>ans;
        int maxi=INT_MIN;
        Break(0,n,ans, result, maxi);

        return maxi;
        
    }
};