class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int l=0;
        int r=0;
        unordered_set<string>st;
        while( r<s.size()){
            if(r-l+1>k){
                l++;
            }
            if( r-l+1==k){
                st.insert(s.substr(l, r-l+1));
            }
            r++;
        }

        if( st.size() == pow(2, k)){
            return true;
        }
        return false;

        
    }
};