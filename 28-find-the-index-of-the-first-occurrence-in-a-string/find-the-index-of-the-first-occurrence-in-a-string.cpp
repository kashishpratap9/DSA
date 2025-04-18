class Solution {
public:
    int strStr(string haystack, string needle) {
        //make the lps for needle;
        vector<int>lps(needle.size(), 0);
         int px=0;
          int sx=1;
          lps[0]=0;
           while( sx<needle.size()){
            if(needle[px]==needle[sx]){
                lps[sx]=px+1;
                px++;
                sx++;
            }else{
                 if(px==0){
                     sx++;
                 }else{
                    px=lps[px-1];
                 }
            }

           }
        //    int len= haystack.size()-needle.size();
           int first=0;
            int second=0;
             while( second< needle.size() && first<haystack.size()){
                if( haystack[first]==needle[second]){
                    first++;
                    second++;

                }else{
                    if( second==0){
                        first++;

                    }else{
                         second=lps[second-1];
                    }
                }
              
             }

               if( second==needle.size()){
                     return first-second;
                }
           return -1;


        
    }
};