class Solution {
public:
    string removeDuplicateLetters(string s) {

        //last visit and visited concept;
        int n = s.size();
        vector<bool>visited(26, false);
        vector<int>lastvisit(26);
         for(int i=0;i<s.size();i++){
             lastvisit[s[i]-'a']=i;
         }

        
         string ans="";
      for( int i=0;i<s.size();i++){
            char ch =s[i];

            if(visited[ch-'a']){
                continue;
            }

            while(!ans.empty() && ans.back() > ch && lastvisit[ans.back()-'a']>i){
                visited[ans.back()-'a']=false;
                ans.pop_back();

            }

            ans.push_back(ch);
             visited[ch-'a']=true;

      }
     

     
        return ans;
    }
};