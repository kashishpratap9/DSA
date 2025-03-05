class Solution {
public:
    long long coloredCells(int n) {
        long long int  val = n;

        return 1 + 4 * (val*(val-1)/2);
        
    }
};