class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>result;
        unordered_map<int,int>mp;
        for(auto e: nums2){
            int id=e[0];
            int val=e[1];
            mp[id]=val;
        }

        for(auto i: nums1){
            int id=i[0];
            int val= i[1];
            vector<int>ans;
            if(mp.find(id)!=mp.end()){
                result.push_back({id, mp[id]+val});
                mp.erase(id);
            }
            else{
                result.push_back(i);
            }
            
        }
    if( mp.size()!=0){
        for(auto i: mp){ 
            result.push_back({i.first, i.second});
        }
    }

        

        auto lambda= [](vector<int>&a1, vector<int>&a2){
            return a1[0]<a2[0];
        };

        sort(result.begin(), result.end(), lambda);
        return result;

        
    }
};