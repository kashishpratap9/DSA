class Solution {
public:
int SumofDigit(int num){
    int sum=0;
     while( num!=0){
        sum+=num%10;
        num/=10;
     }
     return sum;
    
}

    int countLargestGroup(int n) {
        unordered_map<int, int>mp;
        int maxsize=1;
         for( int i=1;i<=n;i++){
            int sum= SumofDigit(i);
            mp[sum]++;
         }
          for( auto i: mp){
            maxsize= max( maxsize, i.second);
          }
          int count=0;

          for( auto i:mp){
            if(i.second==maxsize){
                count++;
            }
          }
         
    return count;
        
    }
};