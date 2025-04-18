class Solution {
public:

bool isSubstring(string&a, string&b){
    if( a.size()< b.size()){
         return false;
    }
    vector<int>lps(b.size(), 0);
     int px=0;
      int sx=1;
       lps[0]=0;
    while(sx<b.size()){
         if( b[px]==b[sx]){
             lps[sx]=px+1;
              sx++;
               px++;
         }else{
            if(px==0){
                 sx++;
            }else{
                 px=lps[px-1];
            }
         }
    }

    int first=0;
     int second=0;
     while( first<a.size() && second<b.size()){
        if( a[first]==b[second]){
            first++;
            second++;
        }else{
            if( second==0){
                 first++;
            }else{
                second= lps[second-1];
            }
        }

     }

     if(second==b.size()){
        return true;
     }
     return false;



}
    int repeatedStringMatch(string a, string b) {

       int count=1;
       string str=a;
       while( a.size()<b.size()){
        a+=str;
        count++;

       }

       if(isSubstring(a, b)){
            return count;
       }

       a+=str;
       count++;
       if(isSubstring(a, b)){
        return count;
       }

       return -1;

        
    }
};