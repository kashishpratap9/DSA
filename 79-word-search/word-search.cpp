class Solution {
public:


bool wordSearch( int i, int j,int k ,vector<vector<char>>&board , string word){
    if(k==word.size()){
        return true;
    }
    //out of bound
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='$'){
        return false;
    }
    
   if( board[i][j]==word[k]){
    char val = board[i][j];
    board[i][j]='$';
     bool found =wordSearch( i+1, j, k+1, board, word) || wordSearch( i-1, j, k+1, board, word) || wordSearch( i, j+1, k+1, board, word) || wordSearch( i, j-1, k+1, board, word);
        board[i][j]=val;

        return found;

   }

   return false;
   

}
    bool exist(vector<vector<char>>& board, string word) {
        int k=0;
         bool ans;
        for( int i=0;i<board.size();i++){
            for( int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                   if(wordSearch(i, j, k, board, word)){
                    return true;
                   }
                }
            }
        }
        return false;
        
    }
};