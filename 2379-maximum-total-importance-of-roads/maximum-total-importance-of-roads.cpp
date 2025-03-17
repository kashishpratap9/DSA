class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // unordered_map<int, vector<int>>adj;
        vector<int>indegree(n, 0);
        for(auto e: roads){
            int u=e[0];
            int v=e[1];
            indegree[u]++;
            indegree[v]++;
        }

        sort(indegree.begin(), indegree.end());
        int cn=1;
        long long sum=0;
        for( int i=0;i<indegree.size();i++){
            if(cn<=n){
            long long val = (long long)indegree[i] * cn;
            sum+=val;
            cn++;
            }

        }

    //     auto lambda= [](pair<int, int>&p1 , pair<int, int>&p2){
    //         return p1.second>p2.second;
    //     };

    //     vector<pair<int, int>>vec(indegree.begin(), indegree.end());
    //     sort(vec.begin(), vec.end(), lambda);
    //     unordered_map<int, int>mp1;
    //    int cn=n;
    //   for(int i=0;i<vec.size();i++){
    //      mp1[vec[i].first]=cn;
    //      cn--;
    //   }
    //   long long sum=0;
    //   for( auto e:roads){
    //     int u=e[0];
    //     int v=e[1];
    //     sum+=mp1[u]+mp1[v];
    //   }

        return sum;

    }
};