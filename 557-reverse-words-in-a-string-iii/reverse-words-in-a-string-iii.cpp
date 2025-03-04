class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
         string token="";
         string ans="";
        
        while(ss >> token){
           string  result = token;
           reverse(result.begin(), result.end());
           ans = ans + " " + result;


        }

        return ans.substr(1, ans.size());
    }
};