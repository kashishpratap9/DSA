class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string , int>mp;
        mp["I"]=1;
        mp["IV"]=4;
        mp["V"]=5;
        mp["IX"]=9;
        mp["X"]=10;
        mp["XL"]=40;
        mp["L"]=50;
        mp["XC"]=90;
        mp["C"]=100;
         mp["CD"]=400;
        mp["D"]=500;
        mp["CM"]=900;
        mp["M"]=1000;
        int result=0;
         for( int i=0;i<s.size();i++){
            string v="";
            if( i+1 <s.size() && s[i]=='I' && (s[i+1]=='V'|| s[i+1]=='X')){
                v.push_back(s[i]);
                v.push_back(s[i+1]);
                result+=mp[v];
                i++;
            }else if( i+1 <s.size() && s[i]=='X' && (s[i+1]=='L'|| s[i+1]=='C')){
                 v.push_back(s[i]);
                v.push_back(s[i+1]);
                result+=mp[v];
                i++;

            }else if(i+1 <s.size() && s[i]=='C' && (s[i+1]=='M'|| s[i+1]=='D')){
                 v.push_back(s[i]);
                v.push_back(s[i+1]);
                result+=mp[v];
                i++;

            }else{
                v+=s[i];
             result+=mp[v];
            }

            
         }
         return result;

        
    }
};