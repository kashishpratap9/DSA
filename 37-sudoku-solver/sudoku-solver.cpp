class Solution {
public:

bool isPossible(int val, int i, int j , vector<vector<char>>& board){
    int row=0;
    int col=0;
    int n=board.size();
    while(row<n){
       if( board[row][j]==val+'0'){
         return false;
       }
       row++;
    }

    while(col<n){
         if( board[i][col]==val+'0'){
            return false;
         }
         col++;
    }
   
 int startRow = (i / 3) * 3, startCol = (j / 3) * 3;
    for( int r=startRow;r<startRow+3;r++){
        for( int c=startCol ; c<startCol+3;c++){
            if( board[r][c]==val+'0'){
                return false;
            }
        }
    }

    return true;
    
}



bool helper(vector<vector<char>>& board){
    //basecase
    for( int i=0;i<board.size();i++){
         for( int j=0;j<board[0].size();j++){
            if( board[i][j]=='.'){
                    for( int val=1;val<=9;val++){
                        if(isPossible(val, i, j, board)){
                            board[i][j]=val+'0';
                            if(helper(board)){
                                return true;
                            }
                            board[i][j]='.';
                         }
                     }
                       return false;

                }
         }
    }

    return true;
      
  
    
}
    void solveSudoku(vector<vector<char>>& board) {
                     
         helper(board);
        
    }
};