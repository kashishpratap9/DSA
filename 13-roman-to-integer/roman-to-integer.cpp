class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char , int>mp;
        mp['I']=1;
       
        mp['V']=5;
   
        mp['X']=10;
      
        mp['L']=50;
   
        mp['C']=100;
 
        mp['D']=500;
  
        mp['M']=1000;
        int result=0;
         for( int i=0;i<s.size();i++){
            if( i+1 <s.size() && s[i]=='I' && s[i+1]=='V'){
                    result+=4;
                i++;
            }else if(i+1 <s.size() && s[i]=='I' && s[i+1]=='X'){
                result+=9;
                 i++;
            }
            else if( i+1 <s.size() && s[i]=='X' && s[i+1]=='L'){
                    result+=40;
                i++;

            }else if(i+1 <s.size() && s[i]=='X' && s[i+1]=='C'){
                 result+=90;
                i++;

            }
            else if(i+1 <s.size() && s[i]=='C' && s[i+1]=='D'){
                    result+=400;
                i++;

            } else if(i+1 <s.size() && s[i]=='C' && s[i+1]=='M'){
                    result+=900;
                i++;

            }
            else{
            
             result+=mp[s[i]];
            }

            
         }
         return result;

        
    }
};