class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>mp;
         for( int i=0;i<s.size();i++){
            mp[s[i]]++;
         }

         int len=0;
        int flag=false;
         for( auto i:mp){
            if( i.second%2==0){
                len+=i.second;

            }else{
                flag= true;
                len+=i.second-1;
            }
         }

         if( flag){
            return len+1;
         }
return len;

        
    }
};