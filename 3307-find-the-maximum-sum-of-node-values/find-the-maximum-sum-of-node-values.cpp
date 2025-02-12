class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // unordered_map<int, vector<int>>adj;
        //     for(auto&e: edges){
        //         int u=e[0];
        //         int v=e[1];
        //         adj[u].push_back(v);
        //         adj[v].push_back(u);
        //     }
         
    //  for( auto&e : edges){
    //     int u=e[0];
    //     int v=e[1];

    //     int val1=nums[u]^k;
    //     int val2=nums[v]^k;
    //     // cout<<nums[u]<<" "<<val1<<endl;
    //     // cout<<nums[v]<<" "<<val2<<endl;
    //     if(val1 > nums[u] || val2 > nums[v]){
    //         nums[u]^=k;
    //         nums[v]^=k;
    //     }

    //  } 

    //     int sum=0;
    //     for( int i=0;i<nums.size();i++){
    //         sum+=nums[i];
    //         cout<<nums[i]<<" ";
            
    //     } 

    //     return sum; 
long long sum=0;
long long nuksan=INT_MAX;
int count=0;
    for(int i=0;i<nums.size();i++){
        long long val= nums[i]^k;
        if( val > nums[i]){
            sum+=val;
            count++;
        }
        else{
            sum+=nums[i];
            
        }

        nuksan= min(nuksan, abs(nums[i]-val));
    }

if(count %2==0){
    return sum;
}


return sum-nuksan;



    }
};