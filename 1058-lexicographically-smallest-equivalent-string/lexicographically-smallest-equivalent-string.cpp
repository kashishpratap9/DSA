class Solution {
public:
char dfs(char src,   vector<int>&visited, unordered_map<char, vector<char>>&adj){
     visited[src-'a']=1;
     char mini=src;
    for(auto & nbr: adj[src]){
         if(visited[nbr-'a']==0){
           mini= min(mini,dfs(nbr, visited, adj));
        }
    }
    return mini;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>>adj;
        int i=0;
        vector<int>visited(26, 0);
        while(i<s1.size()){
            adj[s1[i]].push_back({s2[i]});
            adj[s2[i]].push_back({s1[i]});
            i++;
        }

        string ans="";
        for(int i=0;i<baseStr.size();i++){
        vector<int>visited(26, 0);
         if(visited[baseStr[i]-'a']==0){
                 ans+=dfs(baseStr[i],visited, adj);
                
         }
        }
        return ans;
    }
};