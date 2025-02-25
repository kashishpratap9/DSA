class Solution {
public:

bool isIncreasing(vector<int>&arr){
     for( int i=1;i<arr.size();i++){
         if( arr[i-1]>arr[i]){
             return false;
         }
     }
     return true;
}

void Conversion( priority_queue<int>&pq, vector<int>&result){
    while(!pq.empty()){
        result.push_back( pq.top());
        pq.pop();
    }
}

int findLargestDivisior(int&val){
    int divisor=0;
    for(int i=1;i<val;i++){
         if(val%i==0){
            divisor=i;
         }
    }
    return divisor;
}
    long long minimumReplacement(vector<int>& nums) {
    //     if(isIncreasing(nums)){
    //          return 0;
    //     }
    //     int mini=INT_MAX;
    //     long long ans=0;
    //     for( int i=0;i<nums.size();i++){
    //          mini= min( mini, nums[i]);
    //     }
    //    priority_queue<int>pq(nums.begin(), nums.end());
    //    while(!pq.empty()){
    //     int val =pq.top();
    //     pq.pop();
    //     if(val==mini){
    //     vector<int>result;
    //      Conversion(pq, result);
    //      if(isIncreasing(result)){
    //         return ans;
    //      }
            
    //     }
    //     else{
    //     int val1= findLargestDivisior(val);
    //     // cout<<val1;
    //     pq.push(val1);
    //     pq.push(val-val1);
    //     ans++;
    //     }

    //    }
    //    return ans;

    long long ans=0;
    int n= nums.size();
    for( int i=n-2;i>=0;i--){
        if( nums[i]> nums[i+1]){
            int parts= nums[i]/nums[i+1];
            if( nums[i]%nums[i+1]){
                parts++;
            }
            ans+= parts-1;
            nums[i]=nums[i]/parts;
        }

    }
    return ans;

        
    }
};