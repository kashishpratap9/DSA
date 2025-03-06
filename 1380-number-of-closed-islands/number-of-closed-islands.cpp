class Solution {
public:
vector<vector<int>>directions={{-1, 0},{1,0},{0,-1},{0,1}};
bool dfs(int i, int j , vector<vector<int>>&grid){
    int n= grid.size();
     int m= grid[0].size();
    if(i<0 || j<0 || i>=n|| j>=m){
        return false;
    }
    if( i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
         return true;
    }


    if( grid[i][j]==0){
         grid[i][j]=1;
    }
    bool left=dfs(i, j-1, grid);

    bool right=dfs(i, j+1, grid);
    bool up=dfs(i-1, j, grid);
    bool down=dfs(i+1, j, grid);

    return left && right && up && down;

}

    int closedIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
             for( int j=0;j<grid[0].size();j++){
                if( grid[i][j]==0){
                    if(dfs(i, j, grid)){
                        count++;
                    }
                }
             }
        }
        return count;
        
    }
};