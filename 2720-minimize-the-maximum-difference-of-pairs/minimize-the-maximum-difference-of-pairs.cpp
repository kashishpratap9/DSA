class Solution {
public:
bool isValid( vector<int>&nums, int p , int mid){
    int n= nums.size();
    int cn=0;
    for( int i=0;i<nums.size()-1;i++){
        // cout<<nums[i]<<" "<<nums[i+1]<<endl;
        int diff= abs(nums[i] - nums[i+1]);
        if( diff<=mid){
            cn++;
            i++;
            if( cn>=p){
                return true;
            }
        }
    }
    return cn>=p;

}
    int minimizeMax(vector<int>& nums, int p) {
        //we are sorting it because there can be any  number of pairs so to make it conscutive and also to get the minimum answer we sort them;
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int l=0;
         int r= nums[n-1]-nums[0];
        int ans=-1;
        while(l<=r){
             int mid= l + (r-l)/2;
            if(isValid(nums, p,mid)){
                 ans= mid;
                 r=mid-1;
            }else{
                l= mid+1;
            }
        }
        return ans;
        
    }
};