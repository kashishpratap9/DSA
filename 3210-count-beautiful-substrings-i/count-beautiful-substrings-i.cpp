class Solution {
public:
bool isBeautiful(string&s1, int k){
    int v=0;
     int c=0;
     for( int i=0;i<s1.size();i++){
        char ch =s1[i];
        if(ch=='a' || ch=='e'||ch=='o'||ch=='u'||ch=='i'){
            v++;
        }else{
            c++;
        }
     }

     if( v==c && (v*c)%k==0){
        return true;
     }
     return false;
}
    int beautifulSubstrings(string s, int k) {
        int count=0;
        for( int i=0;i<s.size();i++){
            int c=0;
             int v=0;
             for(int j=i; j<s.size();j++){
                // string s1= s.substr(i, j-i+1);
                // if(isBeautiful(s1, k)){
                //     count++;
                // }

                    if(s[j]=='a' || s[j]=='e'||s[j]=='o'||s[j]=='u'||s[j]=='i'){
                        v++;
                    }else{
                        c++;
                    }

                if( v==c &&(v*c)%k==0){
                    count++;
                }
             }
        }
        return count;
        
    }
};