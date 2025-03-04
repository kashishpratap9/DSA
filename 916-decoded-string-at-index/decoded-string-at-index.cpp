class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // string ans="";
        // for(int i=0;i<s.size();i++){
        //     char ch = s[i];
        //      if( ch>='0' && ch <='9'){
        //         int digit= ch-'0';
        //         int val =digit-1;
        //        while(val>0){
        //         ans+=ans;
        //         val--;
        //        }
        //      }else{
        //         ans+=ch;
        //      }
        // }
        // string val="";

        // for( int i=0;i<ans.size();i++){
        //    if(i==k-1){
        //      val+=ans[i];
        //      return val;
        //    }
        // }
        // return "";

        //we need to keep trck of its length 
        long long len=0;
        for( int i=0;i<s.size();i++){
            char ch =s[i];
             if(ch>='0' &&  ch<='9'){
                int digit=ch-'0';
                len*=digit;
             }else{
                len++;
             }

        }
        string ans="";
   for( int i=s.size()-1;i>=0;i--){
        k=k%len;
        if( k==0 && (s[i]>='a' && s[i]<='z')){
            ans+=s[i];
            return ans;
        }
        if( s[i]>='2' && s[i]<='9'){
            len/=(s[i]-'0');
        }else{
            len=len-1;
        }
    }

        return "";

        
    }
};