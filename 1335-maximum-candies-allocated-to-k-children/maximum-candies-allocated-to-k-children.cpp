class Solution {
public:
bool isPossible(vector<int>candies, long long k, int mid){
    // int cn=0;
    long long sum=0;
    for( int i=0;i<candies.size();i++){
        sum+=(candies[i]/mid);  
    }

    if(sum>=k){
         return true;
    }

    return false;
}
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        int maxi=INT_MIN;
        // int mini=INT_MAX;
        for( int i=0;i<candies.size();i++){
            sum+=candies[i];
            maxi=max(maxi, candies[i]);
            // mini= min(mini, candies[i]);
        }
        if( sum < k){
            return 0;
        }

        int l=1;
        int r=maxi;
        int ans=0;
        while( l<=r){
            int mid = l +(r-l)/2;
            if(isPossible(candies,k , mid)){
                ans=mid;
                l= mid+1;
            }else{
                r= mid-1;
            }
        }

        return ans;


        
    }
};