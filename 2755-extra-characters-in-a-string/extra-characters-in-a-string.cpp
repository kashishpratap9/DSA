class Solution {
public:


int Extra( int i, string s,set<string>&st, vector<int>&dp){
    if(i>=s.size()){
         return 0;
    }

    if(dp[i]!= -1){
         return dp[i];
    }

    int inc=INT_MAX;

    int exc = 1 + Extra(i+1, s, st, dp);
    string curr="";
    for(int j=i;j<s.size();j++){
        curr+=s[j];
        if( st.find(curr)!= st.end()){
            inc= min(inc, Extra(j+1, s, st, dp));
        }
    }
    return  dp[i]=min( inc, exc);
    

     //exclude->take it as an extra character
     


}
    int minExtraChar(string s, vector<string>& dictionary) {

    set<string>st;
    for( int i=0;i<dictionary.size();i++){
        st.insert(dictionary[i]);
    }

    vector<int>dp(s.size()+1, -1);
      return Extra(0, s, st, dp);
        
    }
};