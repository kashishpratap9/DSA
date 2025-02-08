class Solution {
public:

bool compare(string&s1, string&s2){
   if (s2.find(s1) != string::npos){
        return true;
   }
   return false;
   


}
    vector<string> stringMatching(vector<string>& words) {
        set<string>result;
        vector<string>ans;
        for( int i=0;i<words.size();i++){
             string s1=words[i];
             for( int j=0;j<words.size();j++){
                if( i==j){
                     continue;
                }

                if( compare(s1, words[j])){
                    result.insert(s1);
                }

             }
        }

        for( auto i: result){
            ans.push_back(i);
        }

        return ans;
        
        
    }
};