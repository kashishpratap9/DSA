class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {

        unordered_map<int, vector<int>>adj;
        map<string, int>mp;
        int n = friends.size();
        for( int i=0;i<n;i++){
            for( auto v: friends[i]){
                adj[i].push_back(v);
                // adj[v].push_back(i);
            }
        }

        //creating queue
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(id);
        visited[id]=true;
        int k=0;
        while(!q.empty()){
            int size=q.size();
             for( int i=0;i<size;i++){
                int node= q.front();
                 q.pop();

                if( k>level){
                break;
                 }

                 if( k==level){
                   for( int j=0;j<watchedVideos[node].size() ;j++){
                    mp[watchedVideos[node][j]]++;
                   }
                 }
                 for(auto &nbr: adj[node]){
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        q.push(nbr);
                    }
                 }
             }
             k++;
        }

vector<string>ans;
vector<pair<string, int>>result;
for( auto i: mp){
     result.push_back({i.first, i.second});
}
  

auto lambda= [](pair<string, int>&p1, pair<string, int>&p2){
   if( p1.second==p2.second){
        return p1.first<p2.first;
    }
    else {
        return p1.second<p2.second;
    }
};

sort(result.begin(), result.end(), lambda);
for( auto i: result){
     ans.push_back(i.first);
}

      return ans;




        
    }
};