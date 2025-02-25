class Solution {
public:
int MakeUnique( vector<int>&ans){
    int moves=0;
    unordered_set<int>st;
    for( int i=0;i<ans.size();i++){
        while(ans[i]>0 && st.find(ans[i])!=st.end()){
            ans[i]= ans[i]-1;
            moves++;
        }
        st.insert(ans[i]);
    }
cout<<moves;
    return moves;
}
    int minDeletions(string s) {
        sort(s.begin(), s.end());
        unordered_map<char , int>mp;
        for( int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        vector<int>ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }

        int result=MakeUnique(ans);
        return result;
        
    }
};