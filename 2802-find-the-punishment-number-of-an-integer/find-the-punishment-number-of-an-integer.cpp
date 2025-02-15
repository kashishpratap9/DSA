class Solution {
public:

bool Canpartitioned(int i, string square1, int num, int valsum){
    //base case
if( i==square1.size()){
    if(valsum==num){
    return true;
}
return false;

}


    for(int j=i; j<square1.size();j++){
        int part=stoi(square1.substr(i, j-i+1));
       if(Canpartitioned(j+1, square1, num, valsum + part)){
         return true;
       }
    }

    

    return false;


}
    int punishmentNumber(int n) {
        int  sum=0;

        for( int i=1;i<=n;i++){
            int valsum=0;
            if(Canpartitioned(0,to_string(i*i), i, valsum)){
                sum+=i*i;
            }
        }

        return sum;
        
    }
};