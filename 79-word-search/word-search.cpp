class Solution {
public:
vector<vector<int>>directions={{1,0},{-1, 0},{0,1},{0,-1}};
bool dfs( int i, int j , int k, string ans,string&word, vector<vector<char>>& board){
    int n =board.size();
    int m =board[0].size();
    if(ans.size()==word.size()){
        return true;
    }

    if( i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[k] || board[i][j]=='$'){
        return false;
    }

    char val = board[i][j];
    ans+=val;
    board[i][j]='$';
    k++;
    // for(auto dir: directions){
    //     int i_=i+ dir[0];
    //     int j_= j+ dir[1];
    //     if( i_>=0 && i_<n && j_>=0&&  j_<m){
    //         dfs( i_, j_,k+=1,flag,word, board);
    //         board[i][j]=val;
    //     }
    // }
    bool d=dfs(i+1, j, k,ans, word, board);
    bool u=dfs(i-1, j, k,ans,word, board);
    bool l=dfs(i, j-1, k,ans, word, board);
    bool r=dfs(i, j+1, k,ans,word, board);
    board[i][j]=val;
    ans.pop_back();


    return d||u||l||r;

   




}
    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size();
         int m =board[0].size();
         int k=0;
          for( int i=0;i<n;i++){
            for( int j=0;j<m;j++){
                string ans="";
                if(board[i][j]==word[0]){
                    if(dfs(i, j,0,ans, word, board)){
                        return true;
                    }
                    
                }

            }
          }
          return false;
        
    }
};