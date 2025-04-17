class Solution {
public:
    string sortVowels(string s) {
        vector<char>vowels;
        for( int i=0;i<s.size();i++){
             if( s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u' ||s[i]=='A'|| s[i]=='E' || s[i]=='I' || s[i]=='O'|| s[i]=='U'){
                vowels.push_back(s[i]);
             }
        }

        sort(vowels.begin(), vowels.end());
    
        
        string str="";
        int j=0;
         for( int i=0;i<s.size(); i++){
            if( s[i]!='a' &&s[i]!='e' && s[i]!='i' && s[i]!='o' &&  s[i]!='u' &&  s[i]!='A' &&  s[i]!='E'  && s[i]!='I' &&  s[i]!='O'&&  s[i]!='U'){
                str+=s[i];
             }
             else{
                if( j<vowels.size()){
                str+=vowels[j++];
                }
             }

         }
         return str;
        
    }
};