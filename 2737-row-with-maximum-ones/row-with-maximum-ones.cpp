class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<pair<int,int>>arr;
        for( int i=0;i<mat.size();i++){
             int sum=0;
             for( int j=0;j<mat[0].size();j++){
                 sum+=mat[i][j];
             }
            //  cout<<sum;
             arr.push_back({i, sum});

        }
        auto lambda= [](pair<int, int>&p1, pair<int, int>&p2){
           if( p1.second==p2.second){
            return p1.first<p2.first;
           }

           return p1.second> p2.second;

        };

        sort( arr.begin(), arr.end(), lambda);

        // for( int i=0;i<arr.size();i++){
        //      cout<<'{'<<arr[i].first<<','<<arr[i].second<<'}'<<endl;

        // }

        
        return {arr[0].first, arr[0].second};

        
    }
};