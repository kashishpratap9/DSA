class Solution {
public:

bool dfsCycle(int src, vector<bool>&visited,vector<bool>&inRecursion, unordered_map<int, vector<int>>&adj){
    visited[src]= true;
    inRecursion[src]= true;
    
    for(auto nbr: adj[src]){
      if(visited[nbr] && inRecursion[nbr]){
        return true;
      }
       else if(!visited[nbr]){
            if(dfsCycle(nbr, visited,inRecursion, adj)){
                return true;
            }
      }
    }

     inRecursion[src]=false;

      return false;
    
}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;
         for(auto e:prerequisites){
             int u=e[0];
             int v=e[1];
             adj[v].push_back(u);
         }
         vector<bool>visited(numCourses, false);
         vector<bool>inRecursion(numCourses, false);

         for( int i=0;i<numCourses;i++){
            if(!visited[i] && dfsCycle(i, visited,inRecursion, adj)){
                    return false;
                }
            

         }
         
         return true;
        
    }
};