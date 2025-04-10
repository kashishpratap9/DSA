class Solution {
public:
    string minWindow(string s, string t) {
      int hash[256]={0};
       for( int i=0;i<t.size();i++){
        hash[t[i]]++;
       }
        int l=0;
        int r=0;
        int minlen=INT_MAX;
        int count=0;
        int si=-1;
    
        while(r<s.size()){
         
         if( hash[s[r]]>0){
                count++;
          }


         hash[s[r]]--;
    
        while(count==t.size()){
            if (r - l + 1 < minlen) {      // Added condition check to update minlen
                minlen = r - l + 1;
                si = l;
            }

            hash[s[l]]++;
            if( hash[s[l]]>0){
                count--;
            }
            l++;
         }
         r++;
          }

          return (si == -1) ? "" : s.substr(si, minlen);
        
    
        
    }
};