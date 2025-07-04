class Solution {
public:

string Conversion(string word){
    string res="";
    for( int i=0;i<word.size();i++){
        char ch = word[i];
        res+=(ch+1);
    }
    return res;

}
    char kthCharacter(int k) {
        string word = "a";
        while( word.size()<k){
            string original = word;
            string nextch= Conversion(word);
            word+=nextch;
        }

        return word[k-1];
        
    }
};