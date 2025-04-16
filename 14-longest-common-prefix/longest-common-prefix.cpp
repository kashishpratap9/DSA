class Solution {
public:
void check(string&prev, string&str, string&val){
    int i=0;
     int j=0;
     while(i<prev.size() && j<str.size()){
        if(prev[i]!=str[j]){
            break;
        }
        val+=str[j];
        i++;
        j++;
     }

}
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";
        string prev="$";
        int maxlen=0;
        if( strs.size()==1){
             return strs[0];
        }
         for(auto str:strs){
            if( prev=="$"){
                prev=str;
            }else{
                string val="";
                check(prev, str,val);
                if(val=="" ){
                    return "";
                }
                prev=val;
            }
        
         }
         return prev;

        
    }
};