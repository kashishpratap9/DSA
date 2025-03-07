class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        vector<int>isPrime(right+1, true);
        if(right-left==0){
            return {-1, -1};
        }

        
        
        
        isPrime[0]=false;
        isPrime[1]=false;
         for( int i=2;i*i<=right;i++){
            if(isPrime[i]==true){
                for(int j=2;i*j<=right;j++){
                    isPrime[i*j]=false;
                }
            }
         }

vector<int>ans;

         for( int i=left;i<=right;i++){
            if(isPrime[i]){
              ans.push_back(i);
            }
         }

         if( ans.size()<2){
            return {-1, -1};
         }

         int mini=INT_MAX;
            vector<int>result(2, -1);
         for( int i=0;i<ans.size()-1;i++){
            if((ans[i+1]-ans[i])<mini){
                    mini=ans[i+1]-ans[i];
                   result[0]=ans[i];
                   result[1]=ans[i+1];
              }

         }
         return result;

       
        
    }
};