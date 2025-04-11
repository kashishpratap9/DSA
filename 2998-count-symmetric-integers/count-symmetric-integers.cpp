class Solution {
public:

int Sum_digit(string &str){
    int sum=0;
     for( int i=0;i<str.size();i++){
        sum+=str[i]-'0';
     }
     return sum;
}
bool isPossible(string&val){
    int len=val.size();
    string first=val.substr( 0, len/2);
    string last= val.substr(len/2, len);
    int val1=Sum_digit(first);
    int val2=Sum_digit(last);
    return val1==val2; 

}
    int countSymmetricIntegers(int low, int high) {
        int count=0;
         for( int i=low;i<=high;i++){
            string val = to_string(i);
             if( val.size()%2==0){
                 if(isPossible(val)){
                    count++;

                 }
             }

         }
         return count;
        
    }
};