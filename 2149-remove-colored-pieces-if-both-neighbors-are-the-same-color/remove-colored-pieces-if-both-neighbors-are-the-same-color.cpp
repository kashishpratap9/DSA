class Solution {
public:
    bool winnerOfGame(string s) {
        //both events are independent on each other 
        if(s.size()==2){
             return false;
        }
        int wina=0;
        int winb=0;
        for( int i=1;i<s.size()-1;i++){
            if( i-1>=0  && i+1< s.size() && s[i]=='A' && s[i-1]==s[i] && s[i]==s[i+1]){
                wina++;
            }

        }

         for( int i=1;i<s.size()-1;i++){
            if( i-1>=0  && i+1< s.size() && s[i]=='B' && s[i-1]==s[i] && s[i]==s[i+1]){
                winb++;
            }

        }
        return wina>winb;


        
    }
};