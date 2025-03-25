class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int>prefix(n,1);
        vector<int>postfix(n, 1);
        prefix[0]=nums[0];
        postfix[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        for( int i=n-2; i>=0;i--){
             postfix[i]=postfix[i+1]*nums[i];
        }
        vector<int>ans(n);
        for( int i=0;i<nums.size();i++){
            if( i==0){
               ans[i]=postfix[i+1]; 
            }
            else if(i==n-1){
                ans[i]=prefix[i-1] *1;
                
            }else{
                 ans[i] = prefix[i-1]*postfix[i+1];   
            }
        }
        return ans;
        
    }
};