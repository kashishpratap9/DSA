class Solution {
public:
bool isSafe(int i, int j, vector<string>&board1, int n){

    int row= i;
    int col= j;
 while( i >=0  && j>=0 )
{
    if(board1[i][j] =='Q'){
        return false;
    }

    i--;
    j--;

}


//  left side'

i=row;
j= col;
//diagonally down
while( j>=0){
      if(board1[i][j] =='Q'){
        return false;
    }
    j--;

}

i=row;
j= col;
while( i < n && j >=0){
      if(board1[i][j] =='Q'){
        return false;
    }  
    j--;
    i++;


}
return true;


}

void place_queen(int col ,vector<string>&ans, int&count,int n){
 
    if(col>=n){
       count++;
        return;
    }
    for(int row=0;row<n; row++){
        if(isSafe(row, col, ans, n)){
            ans[row][col]='Q';
            place_queen(col+1, ans,count, n);
            ans[row][col]='.';
        }
    }
 
}
 
    
    int totalNQueens(int n) {
          vector<vector<string>>board;
          int count=0;
        vector<string>ans(n, string(n, '.'));
        place_queen(0, ans,count, n); 
        return count;
        
    }
};