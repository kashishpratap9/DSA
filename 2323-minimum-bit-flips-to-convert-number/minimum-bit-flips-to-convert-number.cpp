class Solution {
public:
    int minBitFlips(int start, int goal) {

        int num= start^goal;
        // now we have to count the number of set bits
        int count=0;
         while( num!=0){
            num= num&num-1;
            count++;
         }
         return count;
        
    }
};