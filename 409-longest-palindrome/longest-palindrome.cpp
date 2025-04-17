class Solution {
public:
    int longestPalindrome(string s) {
       int hash[256]={0};
         for( int i=0;i<s.size();i++){
            hash[s[i]]++;
         }

         int len=0;
        int flag=false;
         for( int i=0;i<256;i++){
            if(hash[i]%2==0){
                len+=hash[i];

            }else{
                flag= true;
                len+=(hash[i]-1);
            }
         }

         if( flag){
            return len+1;
         }
return len;

        
    }
};