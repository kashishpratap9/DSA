class Solution {
public:
bool func(string&s){
    int l=0;
    int r=s.size()-1;
     while(l<=r){
        cout<<s[l]<<" "<<s[r];
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
     }
     return true;
}
    bool isPalindrome(string s) {
        string ans="";

         for( char ch : s){
            if((ch >='a' && ch<='z') || (ch>='A' && ch<='Z')||ch>='0' && ch<='9'){
                ans+=tolower(ch);
            }
         }
       
      

        return func(ans);
        
    }
};