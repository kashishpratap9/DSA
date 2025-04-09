class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        unordered_map<char , int>mp;
        int maxlen=0;
        while( r<n){
            while(mp.find(s[r])!=mp.end()){
                mp.erase(s[l]);
                 l++;
            }
            if(mp.find(s[r])==mp.end()){
                mp[s[r]]++;
            }
            
            maxlen= max(maxlen,r-l+1);
            r++; 
        }
        return maxlen;

        
    }
};