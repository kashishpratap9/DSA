class Solution {
public:
bool valid(int i , int j, char ch ,vector<vector<char>>& board){
    int row=0;
    int col=0;
    int n = board.size();
    while( row<board.size()){
        if( row!=i && board[row][j]==ch){
            return false;
        }
        row++;
    }

     while( col< board.size()){
        if(col!=j && board[i][col]==ch){
            return false;
        }col++;
    }

    int sr=  (i/3)*3;
    int sc= (j/3)*3;
    for( int i1=sr;i1<sr+3;i1++){
        for( int j1=sc;j1<sc+3;j1++){
            if( i1!=i && j1!=j && board[i1][j1]==ch){
                return false;
            }

        }

    }

    return true;

}
    bool isValidSudoku(vector<vector<char>>& board) {
         for( int i=0;i<board.size();i++){
             for( int j=0;j<board[0].size();j++){
                 if( board[i][j]!='.'){
                    if(!valid(i, j,board[i][j], board)){
                        return false;
                    }
                 }
             }
         }
         return true;
        
    }
};