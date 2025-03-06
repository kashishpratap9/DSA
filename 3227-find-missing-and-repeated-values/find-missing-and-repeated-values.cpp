class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int>mp;
        vector<int>ans;
        int n= (grid.size())*(grid.size());
        for( int i=0;i<grid.size();i++){
             for( int j=0;j<grid[0].size();j++){
                    if(mp.find(grid[i][j])!=mp.end()){
                            ans.push_back(grid[i][j]);
                    }
                    mp[grid[i][j]]++;
                    
             }
        }

        // for( auto )

        for(int i=1;i<=n;i++){
             if(mp.find(i)==mp.end()){
                ans.push_back(i);
                return ans;
             }
        }
        // return ans;
        return {};

        
    }
};