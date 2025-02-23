class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //starting from i=0 j=last colum
        int i=0;
        int j=matrix[0].size()-1;

        while(i<matrix.size() && j >=0){
                if( matrix[i][j] == target){
                        return true;
                }
            else if(matrix[i][j] < target){
                i++;
                
             } else if( matrix[i][j] > target){
                j--;
            }

        }
        return false;
        
    }
};