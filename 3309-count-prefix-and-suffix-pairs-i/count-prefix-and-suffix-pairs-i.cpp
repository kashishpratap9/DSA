class Solution {
public:


bool isPrefixAndSuffix(string&str1, string&str2){
    int i=0;
   
    if(str1.size() > str2.size()){
       return false;

    }
    bool  prefix= true;
    bool suffix= true;
    while(i<str1.size()){
        if(str1[i]!=str2[i]){
            prefix= false; 
            break; 
        }
        i++;
    }
    i=0;
    int size= str2.size()-str1.size();
   
    while(i<str1.size()){
        if( str1[i]!=str2[size+i]){
            suffix= false;
            break;
        }
        i++;
    }

    return prefix && suffix;
    
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for( int i=0;i<words.size()-1;i++){
            for( int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }

            }
        }

        return count;
        
    }
};