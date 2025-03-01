class Solution {
public:
void dfs(int src , vector<bool>&visited, vector<vector<int>>&stones){
    visited[src]= true;
    for( int i=0;i<stones.size();i++){
         int r= stones[i][0];
          int c= stones[i][1];
           if(!visited[i] && (stones[src][0]==r || stones[src][1]==c)){
            dfs(i, visited, stones);
           }
    }

}
    int removeStones(vector<vector<int>>& stones) {
      //formula for this questions is like from group of the people that are present in the either the smae row or the same column  now in each group there is only one person that is going to be survive
      // so the overall formula is n - no of grups formed
      int n= stones.size();
      vector<bool>visited(n, false);
      int group=0;
       for( int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited, stones);
            group++;
        }
       }
       return n-group;
        
    }
};