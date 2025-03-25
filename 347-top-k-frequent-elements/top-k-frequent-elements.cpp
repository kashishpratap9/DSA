class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for( int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>>pq;
        for( auto it:mp){
            pq.push({it.second, it.first});
        }
        vector<int>ans;
        while(!pq.empty() && k!=0){
            auto p=pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }
        return ans;
    }
};