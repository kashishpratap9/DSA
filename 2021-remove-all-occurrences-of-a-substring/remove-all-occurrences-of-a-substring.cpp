class Solution {
public:
    string removeOccurrences(string s, string part) {
         
         string result="";
         for( int i=0;i<s.size();i++){


             result+=s[i];
           if(result.find(part)!= string::npos){
            int index=result.find(part);
            cout<<index; 
            result.erase(index, part.size());
           }
           
           

         }
         return result;

        
    }
};